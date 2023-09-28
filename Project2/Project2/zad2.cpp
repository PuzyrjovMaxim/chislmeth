#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;

int main() {
	ifstream fin("Matrix.txt");
	ofstream fout("Answer.txt");
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
	double* y = new double[n];
	double** t1 = new double* [n];
	for (int i = 0; i < n; i++) {
		t1[i] = new double[n];
	}
	double** t2 = new double* [n];
	for (int i = 0; i < n; i++) {
		t2[i] = new double[n];
	}
	double* x = new double[n];
	t1[0][0] = sqrt(a[0][0]);
	for (int j = 1; j < n; j++) {
		t1[0][j] = a[0][j] / t1[0][0];
	}
	for (int j = 0; j < n; j++) {
		double sum1 = 0;
		for (int i = 0; i < n; i++) {
			double sum2 = 0;
			if (j > i) {
				for (int m = 0; m < i; m++) {
					sum2 += t1[m][i] * t1[m][j];
				}
				t1[i][j] = (a[i][j] - sum2) / t1[i][i];
				sum1 += pow(t1[i][j], 2);
			}
			else if (j == i) {
				t1[i][j] = sqrt(a[i][j] - sum1);
			}
			else t1[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			t1[i][j] = t2[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			if (j < i) {
				sum += t2[i][j] * y[j];
			}
			else if(i==j) y[i] = (b[i] - sum) / t2[i][i];
		}
	}
	for (int i = n-1; i <=0; i++) {
		double sum = 0;
		for (int j = n-1; j <= 0; j++) {
			if (i == j) {
				x[i] = (y[i] - sum) / t1[i][i];
			}
			else if (i < j) {
				sum += t1[i][j] * x[j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		fout << x[i] << "; ";
	}
	return 0;
}