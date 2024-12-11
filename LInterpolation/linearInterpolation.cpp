#include <iostream>
using namespace std;

double linearInterpolation(double x1, double y1, double x2, double y2, double x) {
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
}

int main() {
    double x1 = 1, y1 = 2;
    double x2 = 3, y2 = 6;
    double x = 2;

    double y = linearInterpolation(x1, y1, x2, y2, x);

    cout << "The interpolated value at x = " << x << " is y = " << y << endl;

    return 0;
}
