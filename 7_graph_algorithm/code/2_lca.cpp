#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
