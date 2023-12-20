#include <iostream>
#include <cmath>
#include<Windows.h>

using namespace std;

double proizv(double (*f)(double), double a, double b, double h) {
	return (f(b) - f(a - h)) / h;
}

double secondpor(double (*f)(double), double a, double b, double h) {
	return(-3 * f(a) + 4 * f(a + h) - f(a + 2 * h)) / (2 * h);
}

double fourthpor(double (*f)(double), double a, double b, double h) {
	return (f(a - 2 * h) - 8 * f(a - h) + 8 * f(a + h) - f(a + 2 * h)) / (12 * h);
}

// Пример использования
double Func(double x) {
	return x*x;
}

HANDLE hConsole;

int main() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	double a = 1;
	double b = 1.01;
	double h = 0.01;
	double n = 10;
	double l = (b - a) / n;
	cout << l << endl;
	for (double i = l; i <= n*l; i += l) {
		double firstproizv = proizv(Func, a, (a + l), h);
		double secpor = secondpor(Func, a, (a + l), h);
		double fourpor = fourthpor(Func, a, (a + l), h);
		cout << a << ": ";
		SetConsoleTextAttribute(hConsole, 15);  cout << "first proizv: "; SetConsoleTextAttribute(hConsole, 5); cout << firstproizv << "; ";
		SetConsoleTextAttribute(hConsole, 15); cout << "2 por: "; SetConsoleTextAttribute(hConsole, 2); cout << secpor << "; ";
		SetConsoleTextAttribute(hConsole, 15); cout << "4 por: "; SetConsoleTextAttribute(hConsole, 6); cout << fourpor << "; ";
		cout << endl;
		a += l;
	}
	SetConsoleTextAttribute(hConsole, 15);


	return 0;
}