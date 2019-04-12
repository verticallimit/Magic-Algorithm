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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
    }
    topo();
    return 0;
}
