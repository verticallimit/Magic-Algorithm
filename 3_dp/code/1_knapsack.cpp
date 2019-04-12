// 01 背包
#include <iostream>
#include <string.h>
using namespace std;

int dp[21][1010];
int w[21], c[21];

int main() {
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) {
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if(j >= c[i]) {
                dp[i][j] = max(dp[i - 1][j - c[i]] + w[i], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][V] << endl;
    return 0;
}
