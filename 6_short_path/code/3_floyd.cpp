#include <iostream>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int n;
void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }
    floyd();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
4
0 3 1 4
1 0 3 5
10 2 0 7
1 2 3 0
*/
