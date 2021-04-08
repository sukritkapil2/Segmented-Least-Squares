#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

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

vector<Line> FindSegmentedLeastSquares(vector<Point> V, int C) {
    vector<Line> result;

    return result;
}