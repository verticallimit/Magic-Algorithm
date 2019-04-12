#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int dp[110][110];
int main() {
    string a, b;
    memset(dp, 0, sizeof(dp));
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    for(int i = 1; i <= lena; ++i) {
        for (int j = 1; j <= lenb; ++j) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[lena][lenb] << endl;
    return 0;
}
