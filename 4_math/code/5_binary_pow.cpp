#include <iostream>
using namespace std;

int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}

int main() {
    int a, b, mod;
    cin >> a >> b >> mod;
    cout << Pow_mod(a, b, mod) << endl;
    return 0;
}
