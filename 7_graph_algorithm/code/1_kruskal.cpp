#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x = get(e[i].u), y = get(e[i].v);
        if (x != y) {
            fa[x] = y;
            sum += e[i].w;
        }
    }
    cout << sum << endl;
    return 0;
}
