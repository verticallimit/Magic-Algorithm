#include <iostream>
#include <string.h>

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
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= scc; ++i) {
        cout << "block " << i << ": ";
        for (int j = 1; j <= n; ++j) {
            if (belong[j] == i) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
