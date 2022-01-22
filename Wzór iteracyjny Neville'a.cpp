#include <vector>

using namespace std;

struct point {
    double x, y;
};

double neville_interpolation(vector<point> pt, const double t) {
    const int n = pt.size();
    double total;
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            pt[i].y = ((t - pt[i - j].x) * pt[i].y - (t - pt[i].x) * pt[i - 1].y) / (pt[i].x - pt[i - j].x);
        }
    }
    total = pt[n - 1].y;
    return (total);
}

#include <iostream>

int main() {
    vector<point> points{ {1,1},{2,4},{3,9},{4,4},{5,1} };
    cout << neville_interpolation(points, 1.5) << endl;
    cout << neville_interpolation(points, 2.5) << endl;
    cout << neville_interpolation(points, 3.5) << endl;
    cout << neville_interpolation(points, 4.5) << endl;
}