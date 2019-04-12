#include <iostream>
#include <cstring>

using namespace std;

int n;
bool flag = 0;
int G[20][20];
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
void dfs(int deep) {
    if (flag == 1) {
        return;
    }
    if (deep >= n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
        flag = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (x1[i + deep] == false && y1[i - deep + n] == false && a[i] == false) {
            x1[deep + i] = true;
            y1[i - deep + n] = true;
            a[i] = true;
            G[deep][i] = 1;
            dfs(deep + 1);
            a[i] = false;
            x1[deep + i]=false;
            y1[i - deep + n] = false;
            G[deep][i] = 0;
        }
    }
}
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));
    dfs(0);
    return 0;
}
