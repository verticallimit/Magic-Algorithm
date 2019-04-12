#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}

int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}

int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;
    cout << dinic() << endl;
    return 0;
}
