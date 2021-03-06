/**
 * @file primitives.h
 * This file contains function declarations of the functions defined in the file primitives.cpp
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Point Primitive Class
*/
class Point {
    double x;
    double y;

    public:
        Point();
        Point(double x, double y);
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
};

/**
 * Line Primitive Class
*/
class Line {
    Point p1;
    Point p2;

    public:
        Line();
        Line(Point p1, Point p2);
        Point getP1();
        Point getP2();
};

/**
 * This function uses dynamic programming to find the segments and returns them in the form of an array of lines
 * @param[in] V vector of input points
 * @param[in] C cost for multiple segments
 * @param[out] Lines vector of segments
*/
vector<Line> FindSegmentedLeastSquares(vector<Point> V, double C);