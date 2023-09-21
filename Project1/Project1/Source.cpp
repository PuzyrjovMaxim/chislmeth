#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	double* b = new double[n];
	double* x = new double[n];
	double q;
	cout << "A:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << i+1 << "." << j+1 << ": " << endl;
			cin >> a[i][j];
		}
	}
	cout << "B: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			q = a[j][i] / a[i][i];
			b[j] -= q * b[i];
			for (int m = i + 1; m < n; m++) {
				a[j][m] -= q * a[i][m];
			}
		}
	}
	for (int i = n-1; i >= 0; i--) {
		double summ = 0;
		for (int j = i + 1; j < n; j++) {
			summ += a[i][j] * x[j];
		}
		x[i] = (b[i] - summ) / a[i][i];
	}
	cout << endl << "X = (";
	for (int i = 0; i < n; i++) {
		cout << x[i] << "; ";
	}
	cout << ")" << endl;
	return 0;
}