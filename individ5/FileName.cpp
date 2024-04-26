#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;


int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	double n, a, b, m, a1, b1;
	double k, **u;
	fin >> n >> m >> a >> b >> a1 >> b1;
	
	u = new double*[n + 1];
	for (int i = 0; i <= n; i++) {
		u[i] = new double[m + 1];
	}

	double hx = (b - a) / n;
	double ht = (b1 - a1) / m;

	double* alpha = new double[n + 1];
	double* betta = new double[n + 1];

	/*alpha[0] = -(ht / pow(hx, 2)) / ((1 + 2 * ht / pow(hx, 2)));
	betta[0] = u[0][0] / ((1 + 2 * ht / pow(hx, 2)));*/

	alpha[0] = 1;
	betta[0] = 0;

	for (int j = 0; j <= n; j++) { // вычисления u[0][x]
		u[0][j] = ((ht / pow(hx, 2)) * betta[0] - 2 * (a + j * hx) * ht * (ht / pow(hx, 2))) / ((ht / pow(hx, 2)) * alpha[0] - (1 + 2 * ht / pow(hx, 2)) + (ht / pow(hx, 2)) - 1);
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			alpha[i] = -ht / pow(hx, 2) / ((ht / pow(hx, 2)) * alpha[i - 1] - (1 + 2 * ht / pow(hx, 2)));
			betta[i] = (u[i - 1][j] - (ht / pow(hx, 2)) * betta[i - 1]) / ((ht / pow(hx, 2)) * alpha[i - 1] - (1 + 2 * ht / pow(hx, 2)));
			u[i][j] = (u[i - 1][j] - betta[i]) / alpha[i];
		}
	}

	fout << "T\tX\tU\n";
	
	for (int i = 0; i <= m; i++) {
		fout << a1 + i * ht << ":\n";
		for (int j = 0; j <= n; j++) {
			fout << "\t" << a + j * hx << ":\t " << u[i][j] << endl;
		}
	}
	return 0;
}