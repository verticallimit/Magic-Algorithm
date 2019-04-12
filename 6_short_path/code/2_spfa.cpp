#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }
    spfa(1);
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }
    return 0;
}
/*
5 6
1 2 3
2 3 2
3 4 1
2 4 10
4 5 1
1 3 7
*/
