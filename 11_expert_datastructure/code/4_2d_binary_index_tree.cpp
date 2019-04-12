#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }
    int x, y;
    cin >> x >> y;
    cout << getsum(x, y) << endl;
    return 0;
}
