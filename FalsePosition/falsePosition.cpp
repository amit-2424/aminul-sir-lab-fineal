#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double function(double x) {
    return 2* x * x * x - 2 * x - 5;
}

void falsePosition(double a, double b, double tolerance, int maxIterations) {
    if (function(a) * function(b) >= 0) {
        cout << "Invalid interval: The function must have opposite signs at a and b." << endl;
        return;
    }

    double c;
    for (int i = 0; i < maxIterations; i++) {
        c = (a * function(b) - b * function(a)) / (function(b) - function(a));

        if (function(c) < tolerance) {
            cout << "The root is: " << c << " after " << i + 1 << " iterations." << endl;
            return;
        }

        if (function(a) * function(c) < 0) {
            b = c;
            cout << fixed << setprecision(3) << "a=" << a << "\t" <<"f(a)=" << function(a) << "\t" << "b=" << b << "\t" << "f(b)=" << function(b) << "\t" << "c=" << c << "\t" << "f(c)=" << function(c) << "\t" << "Updated: b=c" << "\t" << endl;
        } else {
            a = c;
            cout << fixed << setprecision(3) << "a=" << a << "\t" <<"f(a)=" << function(a) << "\t" << "b=" << b << "\t" << "f(b)=" << function(b) << "\t" << "c=" << c << "\t" << "f(c)=" << function(c) << "\t" << "Updated: b=c" << "\t" << endl;
        }
    }
}

int main() {
    double a = 1, b = 2;
    double tolerance = 0.0001;
    int maxIterations = 100; 

    falsePosition(a, b, tolerance, maxIterations);

    return 0;
}
