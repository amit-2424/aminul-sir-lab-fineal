#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double function(double x) {
    return 2 * x * x * x - 2 * x - 5;
}

void bisection(double a, double b, double tolerance) {
    if (function(a) * function(b) >= 0) {
        cout << "Invalid interval: The function must have opposite signs at a and b." << endl;
        return;
    }

    double c;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        if (function(c) == 0.0) {
            break;
        } else if (function(a) * function(c) < 0) {
            b = c;
            cout << fixed << setprecision(3) << "a=" << a << "\t" <<"f(a)=" << function(a) << "\t" << "b=" << b << "\t" << "f(b)=" << function(b) << "\t" << "c=" << c << "\t" << "f(c)=" << function(c) << "\t" << "Updated: b=c" << "\t" << endl;
        } else {
            a = c;
            cout << "a=" << a << "\t" <<"f(a)=" << function(a) << "\t" << "b=" << b << "\t" << "f(b)=" << function(b) << "\t" << "c=" << c << "\t" << "f(c)=" << function(c) << "\t" << "Updated: a=c" << "\t" << endl;
        }
    }

    cout << "The root is:" << c << endl;

}

int main() {
    double a = 1, b = 2;
    double tolerance = 0.0001;
    bisection(a, b, tolerance);

    return 0;
}
