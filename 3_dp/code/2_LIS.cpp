// n^2 和 nlgn 的最长上升子序列

#include <iostream>
#include <string.h>

using namespace std;
int dp[101], a[101], n;

int LIS_nn() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int LIS_nlgn() {
    int len = 1;
    dp[1] = a[1];

    for (int i = 2; i <= n; ++i) {
        if (a[i] > dp[len]) {
            dp[++len] = a[i];
        } else {
            int pos = lower_bound(dp, dp + len, a[i]) - dp;
            dp[pos] = a[i];
        }
    }
    return len;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << LIS_nn() << endl;
    cout << LIS_nlgn() << endl;
    return 0;
}
