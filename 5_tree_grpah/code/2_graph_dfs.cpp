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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
            dfs(E[i].v);
        }
    }
}
int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);
    memset(vst, false, sizeof(vst));
    dfs(1);
    return 0;
}
