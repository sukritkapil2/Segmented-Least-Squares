#include <bits/stdc++.h>

using namespace std;

class Point {
    int x;
    int y;

    public:
        Point();
        Point(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
};

class Line {
    Point p1;
    Point p2;

    public:
        Line();
        Line(Point p1, Point p2);
        Point getP1();
        Point getP2();
};

vector<Line> FindSegmentedLeastSquares(vector<Point> V, int C);