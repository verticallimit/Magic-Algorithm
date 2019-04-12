// 题目背景： https://www.jisuanke.com/course/720/37842 例题1

#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

bool not_intersect(int now, int prev) {
    return (now & prev) == 0;
}

bool fit(int now, int flag) {
    return (now | flag) == flag;
}
bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
}
int count(int now) {
    int s = 0;  // 统计 now 的二进制形式中有多少个 1
    while (now) {
        s += (now & 1);  // 判断 now 二进制的最后一位是否为 1，如果是则累加
        now >>= 1;  // now 右移一位
    }
    return s;
}

int main() {
    int n, m;
    cin >> n >> m;
    // 初始化所有数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int flag;
            cin >> flag;
            state[i] |= (1 << j) * flag;  // 将 (i,j) 格子的状态放入 state[i] 中，state[i] 表示第 i 行的可选格子组成的集合
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << m); ++j) {  // 枚举当前行的状态
            if (!ok(j) || !fit(j, state[i])) {  // 如果当前行状态不合法则不执行后面的枚举
                continue;
            }
            int cnt = count(j);  // 统计当前行一共选了多少个格子
            for (int k = 0; k < (1 << m); ++k) {
                if (ok(k) && fit(k, state[i - 1]) && not_intersect(j, k)) {  // 判断前一行是否合法和当前行和前一行的方案是否冲突
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);  // 更新当前行、当前状态的最优解
                }
            }
        }
    }
    int ans = 0;  // 保存最终答案
    for (int i = 0; i < (1 << m); ++i) {
        ans = max(ans, dp[n][i]);  // 枚举所有状态，更新最大值
    }
    cout << ans << endl;
    return 0;
}
