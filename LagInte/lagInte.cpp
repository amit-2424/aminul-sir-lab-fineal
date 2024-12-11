#include <iostream>
using namespace std;

double lagrangeInterpolation(double x[], double y[], int n, double x_val) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x_val - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {2.0, 4.0, 6.0};
    int n = 3;

    double x_val = 2.5;

    double result = lagrangeInterpolation(x, y, n, x_val);

    cout << "The interpolated value at x = " << x_val << " is " << result << endl;

    return 0;
}
