# stage 模板
- stage

### 文件名
stage.cpp

### 分数
1


---
### 初始化代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
通过本节课，我们学习状态压缩dp问题。

若元素数量比较小（不超过20）时，想要存储每个元素取或不取的状态时，可以借助位运算将状态压缩。
需要借助状态压缩过程的动态规划就是状态压缩DP（很多地方会简称为状压DP）。

题目描述：给定一个n*m的矩阵，行数和列数都不超过20，其中有些格子可以选，有些格子不能选。现在你需要从中选出尽可能多的格子，且保证选出的所有格子之间不相邻（没有公共边）。

我们先定义一些辅助数组。在`main`函数的上方写下

```c++
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
int main() {

    return 0;
}
```


---
### 第二步
#### 讲解
输入`n`和`m`的值。在`main`函数里写下

```c++
int n, m;
cin >> n >> m;
```



#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```

---
### 第三步
#### 讲解
接下来初始化所有的数组。
继续写下
```c++
// 初始化所有数组
for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
        int flag;
        cin >> flag;
        state[i] |= (1 << j) * flag;  // 将 (i,j) 格子的状态放入 state[i] 中，state[i] 表示第 i 行的可选格子组成的集合
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
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

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
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

    return 0;
}
```


---
### 第四步
#### 讲解
接下来我们分析算法的状态转移方程。
我们可以自上而下，一行行地选择格子。在一行内选择格子的时候，只和上一行的选择方案有关，我们就可以将“当前放到第几行、当前行的选择方案”作为状态进行动态规划。
这里，我们就要用到刚刚提到的状态压缩：一行里选择格子的方案实际上是一个集合，我们要将这个集合压缩为一个整数。比如，对于一个3列的矩阵，如果当前行的状态是5就等于二进制的101，那么就意味着当前行选择了第一个和第三个格子；类似地，如果当前行的状态是6等于二进制的110，那么久意味着当前行选择了第一个和第二个格子。
如果上一行的状态是`now`，下一行的状态是`prev`，那么我们只需要确保上下两行选择方案里没有重复的元素，也就是(now & pre) == 0就可以了。
此外，我们还需要判断当前行的状态是否合法，因为读入的矩阵中并不是每个格子都可以选择的，如果我们将矩阵中每行的值也用状态压缩来存储，不妨记为`flag`，那么当前行选择的格子集合一定包含于当前行合法格子的集合，也就是说，(now | flag) == flag必须成立。
这样，我们就可以通过枚举上一行的所有状态，来更新当前行、当前状态的最优解了。直到算完最后一行，统计一下所有状态的最大值即可。
dp[i, j]表示前i行最后一行状态为j的最大格子数
dp[i, j] = max{dp[i, j], dp[i - 1, k] + cnt}  其中k表示上一行的状态，cnt为j状态选择的格子数
根据以上的分析和状态转移方程可以写出
```c++
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
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
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

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];
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

    return 0;
}
```

---
### 第五步
#### 讲解
接下来我们具体实现`ok`函数，判断压缩的状态中格子是否不相邻。在`main`函数上面继续写下
```c++
bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
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

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
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

    return 0;
}
```


---
### 第六步
#### 讲解
接下来我们具体实现`fit`函数，判断压缩的状态中格子是否属于输入的格子状态的子集。在`ok`函数上面继续写下
```c++
bool fit(int now, int flag) {
    return (now | flag) == flag;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

bool fit(int now, int flag) {
    return (now | flag) == flag;
}
bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
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

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

bool fit(int now, int flag) {
    return (now | flag) == flag;
}
bool ok(int x) {
    // 行内自己是否相交
    return (x & (x / 2)) == 0;
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

    return 0;
}
```


---
### 第七步
#### 讲解
接下来我们具体实现`count`函数，统计当前行状态的格子数量。在`main`函数上面继续写下
```c++
int count(int now) {
    int s = 0;  // 统计 now 的二进制形式中有多少个 1
    while (now) {
        s += (now & 1);  // 判断 now 二进制的最后一位是否为 1，如果是则累加
        now >>= 1;  // now 右移一位
    }
    return s;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

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

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 20;
const int MAX_M = 20;
int state[MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_M];

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

    return 0;
}
```


---
### 第八步
#### 讲解
接下来我们具体实现`not_intersect`函数，判断当前行的状态和上一行的状态是否冲突(有相邻格子)。在`fit`函数上面继续写下
```c++
bool not_intersect(int now, int prev) {
    return (now & prev) == 0;
}
```

#### 提示
```c++
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

    return 0;
}
```

#### 代码
```c++
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

    return 0;
}
```


---
### 第九步
#### 讲解
最后我们枚举最后一行的所有状态，求出其中最大值就是所求答案并输出结果。在`main`函数里面写下
```c++
int ans = 0;  // 保存最终答案
for (int i = 0; i < (1 << m); ++i) {
    ans = max(ans, dp[n][i]);  // 枚举所有状态，更新最大值
}
cout << ans << endl;
```

#### 提示
```c++
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
```

#### 代码
```c++
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
```


---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
2 3
1 1 1
0 1 0
```
