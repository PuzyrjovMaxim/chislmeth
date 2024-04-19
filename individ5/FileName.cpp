#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

double Ft(double x, double t) {

}

double Fx(double x, double y) {

}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, a, b, l, m;
	double k, **u;
	fin >> l >> n >> a >> b >> k >> m;
	u = new double* [l];
	for (int i = 0; i < l; i++) {
		u[i] = new double[l];
	}
	double hx = (b - a) / n;
	double ht = (b - a) / m;

}