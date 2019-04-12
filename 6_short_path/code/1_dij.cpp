#include <iostream>
#include <string.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
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
