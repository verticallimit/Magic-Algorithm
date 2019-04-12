#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i < 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j +=i) {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 100; ++i) {
        if (is_prime[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
