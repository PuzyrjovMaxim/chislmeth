#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream fin("matrix.txt");

    int n, i, j, k;
    double A[100][100], B[100][100];
    if (fin.is_open()) {
        fin >> n;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fin >> A[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            B[i][j] = 0;
        }
        B[i][i] = 1;
    }

    // Получение обратной матрицы

    for (int k = 0; k < n; ++k)
    {
        double div = A[k][k];

        for (j = 0; j < n; ++j)
        {
            A[k][j] /= div;
            B[k][j] /= div;
        }

        for (i = k + 1; i < n; ++i)
        {
            double multi = A[i][k];
            for (j = 0; j < n; ++j)
            {
                A[i][j] -= multi * A[k][j];
                B[i][j] -= multi * B[k][j];
            }
        }
    }

    for (int k = n - 1; k > 0; --k)
    {
        for (i = k - 1; i >= 0; --i)
        {
            double multi = A[i][k];
            for (int j = 0; j < n; ++j)
            {
                A[i][j] -= multi * A[k][j];
                B[i][j] -= multi * B[k][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // Обратные иттерации

    float y0[100], y[100], summ = 0, x[100], eps = 0.001, d, d0;

    y0[0] = 1;
    for (i = 1; i < n; i++)
        y0[i] = 0;
    do
    {
        for (i = 0; i < n; i++)
            summ = summ + y0[i] * y0[i];
        d0 = sqrt(summ);
        for (i = 0; i < n; i++)
            x[i] = y0[i] / d0;
        for (i = 0; i < n; i++)
        {
            y[i] = 0;
            for (j = 0; j < n; j++)
                y[i] = y[i] + B[i][j] * x[j];
        }
        summ = 0;
        for (i = 0; i < n; i++)
            summ = summ + y[i] * y[i];
        d = sqrt(summ);
        for (i = 0; i < n; i++)
            y0[i] = y[i];
        summ = 0;
    } while (fabs(d - d0) > eps);

    cout << "\nVector:\n";
    for (i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    cout << "\nLambda = " << 1/d << endl;

    return 0;
}