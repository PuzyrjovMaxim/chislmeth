#include <iostream>
#include <math.h>
using namespace std;
double Func(double x) {
	return 3 *pow(x,2) + 6 * x + 2;
}

int main() {
	double x1;
	double x0 = 10;
	double eps = 0.00001;
	double h = 0.0001;

	double x = x0;
	do {
		x1 = x;
		x = x - Func(x) * h / (Func(x + h) - Func(x));
	} while (abs(x - x1) > eps);

	cout << "Root: " << x << endl;
	return 0;
}