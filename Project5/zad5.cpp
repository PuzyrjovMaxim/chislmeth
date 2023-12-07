#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;

int main() {
	ifstream fin("Matrix.txt");
	int n;
	fin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> a[i][j];
		}
	}
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		fin >> b[i];
	}
	
	double* d = new double[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) d[i] = a[i][j];
		}
	}
	

	double eps = 0.1, x1, y1, z1;
	double x = 1, y = 1, z = 1;
	do {
		x1 = x, y1 = y, z1 = z;
		x = (- a[0][1] * y1 - a[0][2] * z1 + b[0]) / d[0];
		y = (- a[1][0] * x1 - a[1][2] * z1 + b[1]) / d[1];
		z = (- a[2][0] * x1 - a[2][1] * y1 + b[2]) / d[2];
	} while ((abs(x - x1) > eps) and (abs(y - y1) > eps) and (abs(z - z1) > eps));

	cout << "Root: " << x << "; " << y << "; " << z << endl;
	return 0;
}