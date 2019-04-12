#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}
int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    cout << hungury() << endl;
    return 0;
}
