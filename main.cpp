#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

int main() {
    int n, C;
    
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

    vector<Line> result = FindSegmentedLeastSquares(points, C);
}