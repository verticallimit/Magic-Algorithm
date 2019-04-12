#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}

void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;
    while (q--) {
        int d, x, y, c;
        cin >> d >> x >> y;
        if (d == 0) {
            cin >> c;
            modify(1, 1, n, x, y, c);
        } else {
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
