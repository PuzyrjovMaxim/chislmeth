#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double fy(double y, double z) {
	return -2 * y + 4 * z;
}

double fz(double y, double z) {
	return -y + 3 * z;
}

double funcy(double x) {
	return 4 * exp(-x) - exp(2 * x);
}

double funcz(double x) {
	return exp(-x) - exp(2 * x);
}

int main() {
	setlocale(LC_ALL, "rus");

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, i;
	double y0, z0, h, a, b, k1, k2, k3, k4, m1, m2, m3, m4;
	double y[100], x[100], z[100];

	if (fin.is_open()) {
		fin >> n >> a >> b >> y0 >> z0;
		h = (b - a) / n;
		for (i = 0; i <= n; i++) {
			y[i] = 0;
			z[i] = 0;
		}
		for (i = 0; i <= n; i++) {
			x[i] = a + h * i;
		}
		y[0] = y0; z[0] = z0;
	}
	else {
		cout << "Ôàéë íå îòêðûëñÿ." << endl;
		return -1;
	}

	// Получение первого приближение методом Рунге-Кутта 4-го порядка
	for (i = 0; i <= 2; i++) {
		k1 = h * fy(y[i], z[i]);
		m1 = h * fz(y[i], z[i]);

		k2 = h * fy(y[i] + k1 / 2, z[i] + m1 / 2);
		m2 = h * fz(y[i] + k1 / 2, z[i] + m1 / 2);

		k3 = h * fy(y[i] + k2 / 2, z[i] + m2 / 2);
		m3 = h * fz(y[i] + k2 / 2, z[i] + m2 / 2);

		k4 = h * fy(y[i] + k3, z[i] + m3);
		m4 = h * fz(y[i] + k3, z[i] + m3);

		y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		z[i + 1] = z[i] + (m1 + 2 * m2 + 2 * m3 + m4) / 6;
	}
	// метод Адамса-Башфорта
	for (i = 2; i < n; i++) {
		y[i + 1] = y[i] + h * (23 * fy(y[i], z[i]) - 16 * fy(y[i - 1], z[i - 1]) + 5 * fy(y[i - 2], z[i - 2])) / 12;
		z[i + 1] = z[i] + h * (23 * fz(y[i], z[i]) - 16 * fz(y[i - 1], z[i - 1]) + 5 * fz(y[i - 2], z[i - 2])) / 12;
	}

	/*cout << "X\tY" << endl;

	for (i = 0; i <= n; i++) {
		cout << x[i] << "\t" << y[i] << endl;
	}

	cout << "\nÀíàëèòè÷åñêîå ðåøåíèå " <<  endl;

	for (i = 0; i <= n; i++) {
		cout << x[i] << "\t" << func(x[i]) << endl;
	}*/

	fout << "X\tY\tZ" << endl;
	for (i = 0; i <= n; i++) {
		fout << x[i] << "\t" << y[i] << "\t" << z[i] << endl;
	}

	fout << "\nАналитическое решение \n" << endl;
	for (i = 0; i <= n; i++) {
		fout << x[i] << "\t" << funcy(x[i]) << "\t" << funcz(x[i]) << endl;
	}

	return 0;
}
