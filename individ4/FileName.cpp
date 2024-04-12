#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;

double Px(double x) {
	return 4;
}

double Fx(double x) {
	return 8 * pow(x, 3);
}

double Dy(double x, double y) {
	return 4 * y + 8 * pow(x,3);
}

double Y(double x) {
	return 6 * exp(2) * (exp(-2 * x) - exp(2 * x)) / (exp(4) - 1) - 2 * pow(x, 3) - 3 * x;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	double a, b, ya, yb, k1, k2, k3, k4;
	fin >> n >> a >> b >> ya >> yb;
	double h = (b - a) / n;
	double* x = new double[n+1];
	for (int i = 0; i <= n; i++) {
		x[i] = a + i * h;
	}
	double* y = new double[n + 1];
	for (int j = 0; j <= n; j++) {
		y[j] = 0;
	}
	y[0] == ya;
	y[n] = yb;

	/*for (int i = 0; i <= 1; i++) {
		k1 = h * Dy(x[i], y[i]);
		k2 = h * Dy(x[i] + h / 2, y[i] + k1 / 2);
		k3 = h * Dy(x[i] + h / 2, y[i] + k2 / 2);
		k4 = h * Dy(x[i] + h, y[i] + k3);
		y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}*/

	y[1] = Y(x[1]);

	for (int i = 2; i < n + 1; i++) {
		y[i] = (y[i - 1] * (2 / pow(h,2) - 5 / 6 * Px(x[i - 1])) + y[i - 2] * (-1 / pow(h,2) + 1 / 12 * Px(x[i - 2])) + 1 / 12 * Fx(x[i]) + 5 / 6 * Fx(x[i - 1]) + 1 / 12 * Fx(x[i - 2])) / (1 / pow(h, 2) - 1 / 12 * Px(x[i]));
	}

	fout << "X\tY" << endl;
	for (int j = 0; j <= n; j++) {
		fout << x[j] << "\t" << y[j] << endl;
	}

	fout << "\nАналитическое решение\n" << endl;
	for (int i = 0; i <= n; i++) {
		fout << x[i] << "\t" << Y(x[i]) << endl;
	}

	return 0;
}