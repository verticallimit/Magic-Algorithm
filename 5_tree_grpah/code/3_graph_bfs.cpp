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

bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
            }
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
    bfs(1);
    return 0;
}
