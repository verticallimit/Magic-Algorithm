#include <iostream>
using namespace std;
// ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
    return 0;
}
