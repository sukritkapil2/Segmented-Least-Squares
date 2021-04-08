#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

int main() {
    int n;
    double C;
    int choice = 1;

    cout << R"(
   _____                                 _             
  / ____|                               | |            
 | (___   ___  __ _ _ __ ___   ___ _ __ | |_ ___  _ __ 
  \___ \ / _ \/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \| '__|
  ____) |  __/ (_| | | | | | |  __/ | | | || (_) | |   
 |_____/ \___|\__, |_| |_| |_|\___|_| |_|\__\___/|_|   
               __/ |                                   
              |___/                                    

    )" << endl;
    
    cout << "Choose input method: \n";
    cout << "1. Manual\n" << "2. GUI\n" "3. File\n" << endl;

    cout << "\nChoice : ";

    cin >> choice;
    
    if(choice == 1) {
        cout << "Number of points: ";
        cin >> n;

        cout << "Enter " << n << " points in (x, y) format: " << endl;

        vector<Point> points(n+1, Point());

        for(int i = 1;i <= n; i++) {
            int a, b;
            cin >> a >> b;

            points[i].setX(a);
            points[i].setY(b);
        }

        cout << "Enter the value of C (multiple segment penalty): ";
        cin >> C;

        cout << "\nInput Points: \n" << endl;

        for(auto point : points) {
            cout << "( " << point.getX() << " , " << point.getY() << " )" << endl;
        }

        vector<Line> result = FindSegmentedLeastSquares(points, C);
    }
    else if(choice == 2) {

    } else {
        ifstream inputFile;
        string fileName;
        vector<Point> points;

        points.push_back(Point());

        cout << "Enter input file name: ";
        cin >> fileName;

        inputFile.open(fileName);

        if(inputFile.is_open()) {
            string s;
            vector <int> tokens;

            cout << "Enter the value of C (multiple segment penalty): ";
            cin >> C;

            while(getline(inputFile, s)) {
                stringstream check1(s);
                string intermediate;

                while(getline(check1, intermediate, ' ')) {
                    tokens.push_back(stoi(intermediate));
                }

                Point *p = new Point(tokens[0], tokens[1]);
                points.push_back((*p));
                tokens.clear();
            }

            inputFile.close();

            vector<Line> result = FindSegmentedLeastSquares(points, C);
        } else {
            cout << "Error opening file\n" << endl;
        }
    }
    
    return 0;
}