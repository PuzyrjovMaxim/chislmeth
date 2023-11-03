#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;

double P = 0, * x, * y, ** M;

double PX(int i, int j, double *x, double *y, double **M) {
	if (M[j][i] == 1) {
		P = M[i][j];
		return P;
	}
	else {
		if (j - i == 1) {
			P = (y[i] * (x[j] - x[0]) - y[j] * (x[i] - x[0])) / (x[j] - x[i]);
			return P;
		}
		else {
			P = (PX(i, j - 1, x, y, M) * (x[j] - x[0]) - PX(i + 1, j, x, y, M) * (x[i] - x[0])) / (x[j] - x[i]);
			return P;
		}
	}
}

int main() {
	ifstream fin("Znach.txt");
	ofstream fout("Answer.txt");
	int n;
	fin >> n;
	y = new double[n];
	x = new double[n];
	M = new double* [n];
	for (int i = 0; i < n; i++) {
		fin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		fin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (M[j][i] == 0) {
				M[i][j] = PX(i, j, x, y, M);
				if (M[i][j] != 0) {
					M[j][i] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}