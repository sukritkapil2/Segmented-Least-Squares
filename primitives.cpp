#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

bool operator < (Point a, Point b) {
    return a.getX() < b.getX();
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

Line::Line() {
    this->p1 = Point();
    this->p2 = Point();
}

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

Point Line::getP1() {
    return this->p1;
}

Point Line::getP2() {
    return this->p2;
}

vector<Line> FindSegmentedLeastSquares(vector<Point> V, double C) {
    vector<Line> result;
    int n = V.size() - 1;

    ofstream pointsFile, linesFile;
    pointsFile.open("points.txt");
    linesFile.open("lines.txt");

    for(int i = 1;i <= n; i++) {
        pointsFile << V[i].getX() << " " << V[i].getY() << endl;
    }

    pointsFile.close();

    vector<vector<double>> e(n+1, vector<double>(n+1, 0.0));
    vector<double> OPT(n+1, 0);
    vector<int> turns(n+1, 0);

    //Since the algorithm needs points in increasing order, we sort the vector
    sort(V.begin(), V.end());

    cout << "\nPoints after sorting : \n" << endl;

    for(auto point : V) {
        cout << "( " << point.getX() << " , " << point.getY() << " )" << endl;
    }

    //Next, we need to find e(i, j) for each x subinterval from i to j
    //The solution for the best fit line in closed form is with
    //a = (n*S(xy) - S(x)*S(y))/(n*S(x^2)-(S(x)^2))
    //b = (S(y) - a*S(x))/n;

    //Vectors for storing prefix sums
    vector<long long int> sum_x(n+1, 0), sum_y(n+1, 0), sum_x_sq(n+1, 0), sum_xy(n+1, 0);

    for(int j = 1;j <= n; j++) {
        
        //find the jth prefix sum
        sum_x[j] = sum_x[j-1] + V[j].getX();
        sum_y[j] = sum_y[j-1] + V[j].getY();
        sum_x_sq[j] = sum_x_sq[j-1] + V[j].getX() * V[j].getX();
        sum_xy[j] = sum_xy[j-1] + V[j].getX() * V[j].getY();

        for(int i = 1;i <= j; i++) {
            long long int sumX, sumY, sumXY, sumXSq;

            sumX = sum_x[j] - sum_x[i-1];
            sumY = sum_y[j] - sum_y[i-1];
            sumXY = sum_xy[j] - sum_xy[i-1];
            sumXSq = sum_x_sq[j] - sum_x_sq[i-1];

            int num_points = j-i+1;

            long long numerator = num_points * sumXY - sumX * sumY;
            long long denominator = num_points * sumXSq - sumX * sumX;

            double a;

            if (numerator == 0) a = 0.0;
            else {
                a = (denominator == 0) ? numeric_limits<double>::infinity() : numerator/(double) denominator;
            }

            double b = (sumY - a * sumX)/(double) num_points;

            e[i][j] = 0.0;

            for(int t = i;t <= j; t++) {
                double error = V[t].getY() - a * V[t].getX() - b;
                e[i][j] += error * error;
            }
        }
    }

    cout << "\ne Matrix: \n" << endl;

    for(auto row : e) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    for(int j = 1;j <= n; j++) {
        double min_value = numeric_limits<double>::infinity();
        int start = 0;

        for(int i = 1;i <= j; i++) {
            double temp_val = e[i][j] + OPT[i-1];

            if(temp_val < min_value) {
                min_value = temp_val;
                start = i;
            }
        }

        OPT[j] = min_value + C;
        turns[j] = start;
    }

    int end = n;
    int start;

    int count = 0;

    cout << endl;

    while(start > 0) {

        start = turns[end];

        Point p1 = V[start];
        Point p2 = V[end];

        Line *line = new Line(p1, p2);
        result.push_back((*line));
        count++;

        linesFile << p1.getX() << " " << p1.getY() << " " << p2.getX() << " " << p2.getY() << endl;

        cout << "Segment " << count << " from (" << p1.getX() << " , " << p1.getY() << ") to (" << p2.getX() << " , " << p2.getY() << "). e : " << e[start][end] << "\n";

        end = start - 1;
    }

    cout << "\nOPT value : " << OPT[n] << endl;

    return result;
}