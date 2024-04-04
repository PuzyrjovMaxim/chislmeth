#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x, double y) {
	return -2 * x;
}

double func(double x) {
	return -x*x;
}

int main() {
	setlocale(LC_ALL, "rus");

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, i, j;
	double y0, h, a, b, k1, k2, k3, k4;
	double y[100], x[100];

	if (fin.is_open()) {
		fin >> n >> a >> b >> y0;
		h = (b - a) / n;
		for (i = 0; i <= n; i++) {
			y[i] = 0;
		}
		for (i = 0; i <= n; i++) {
			x[i] = a + h * i;
		}
		y[0] = y0;
	}
	else {
		cout << "Ôàéë íå îòêðûëñÿ." << endl;
		return -1;
	}

	// Получение первого приближение методом Рунге-Кутта 4-го порядка
	for (i = 0; i <= 4; i++) {
		k1 = h * f(x[i], y[i]);
		k2 = h * f(x[i] + h/2, y[i] + k1/2);
		k3 = h * f(x[i] + h/2, y[i] + k2/2);
		k4 = h * f(x[i] + h, y[i] + k3);
		y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
	// метод Адамса-Башфорта
	for (i = 4; i < n; i++) {
		y[i + 1] = y[i] + h * (1901 * f(x[i], y[i]) - 2774 * f(x[i - 1], y[i - 1]) + 2616 * f(x[i - 2], y[i - 2]) - 1274 * f(x[i - 3], y[i - 3]) + 251 * f(x[i - 4], y[i - 4])) / 720;
	}

	/*cout << "X\tY" << endl;

	for (i = 0; i <= n; i++) {
		cout << x[i] << "\t" << y[i] << endl;
	}

	cout << "\nÀíàëèòè÷åñêîå ðåøåíèå " <<  endl;

	for (i = 0; i <= n; i++) {
		cout << x[i] << "\t" << func(x[i]) << endl;
	}*/

	fout << "X\tY" << endl;
	for (i = 0; i <= n; i++) {
		fout << x[i] << "\t" << y[i] << endl;
	}

	fout << "\nАналитическое решение \n" << endl;
	for (i = 0; i <= n; i++) {
		fout << x[i] << "\t" << func(x[i]) << endl;
	}

	return 0;
}
