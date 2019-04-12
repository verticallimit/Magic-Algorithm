#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}

int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;
    matrix res = matrix_pow(A, y, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
