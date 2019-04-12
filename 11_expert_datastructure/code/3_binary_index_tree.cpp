#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        change(i, d);
    }
    for (int i = 1; i <= n; ++i) {
        cout << getsum(i) << " ";
    }
    return 0;
}
