#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

int main() {
    int n, C;
    
    cout << "Number of points: ";
    cin >> n;

    cout << "Enter " << n << " points in (x, y) format: " << endl;

    vector<Point> points;

    for(int i = 0;i < n; i++) {
        int a, b;
        cin >> a >> b;

        Point *point = new Point(a, b);

        points.push_back((*point));
    }

    cout << "Enter the value of C (multiple segment penalty): ";
    cin >> C;

    vector<Line> result = FindSegmentedLeastSquares(points, C);
}