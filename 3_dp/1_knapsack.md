# knapsack 模板
- knapsack

### 文件名
knapsack.cpp

### 分数
1


---
### 初始化代码
```c++
// 01 背包
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
通过本节课，我们用动态规划算法来解决一个实际问题——01背包问题。

01背包问题是一个经典的问题，给定N个物品和一个背包。物品i的重量是Wi,其体积为Ci ，背包的容量为C。问应该如何选择装入背包的物品，使得装入背包的物品的总重量为最大

我们先定义一些标记数组。在`main`函数的上方写下

```c++
int dp[21][1010];
int w[21], c[21];
```

#### 提示
```c++
// 01 背包
#include <iostream>
#include <string.h>
using namespace std;

int dp[21][1010];
int w[21], c[21];

int main() {

    return 0;
}
```

#### 代码
```c++
// 01 背包
#include <iostream>
#include <string.h>
using namespace std;

int dp[21][1010];
int w[21], c[21];

int main() {

    return 0;
}
```


---
### 第二步
#### 讲解
下面我们要输入物品的个数N和背包的体积V。在`main`函数里写下

```c++
int N, V;
cin >> N >> V;
```



#### 提示
```c++
// 01 背包
#include <iostream>
#include <string.h>
using namespace std;

int dp[21][1010];
int w[21], c[21];

int main() {
    int N, V;
    cin >> N >> V;

    return 0;
}
```


#### 代码
```c++
// 01 背包
#include <iostream>
#include <string.h>
using namespace std;

int dp[21][1010];
int w[21], c[21];

int main() {
    int N, V;
    cin >> N >> V;

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们继续输入N个物品各自的重量和体积。在`main`函数里面继续写下
```c++
for (int i = 1; i <= N; ++i) {
    cin >> w[i] >> c[i];
}
```

#### 提示
```c++
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

    return 0;
}
```


#### 代码
```c++
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

    return 0;
}
```


---
### 第四步
#### 讲解
接下来是最重要的的一步，对于一个动态规划来说，最重要的是找到状态转移方程。
在01背包问题中，一个物品要么装要么不装，那么我们可以得出下面的式子
f[i,j]代表前i个物品背包容量最大为j最多能装的物品总重量
f[i,j] = Max{ f[i-1,j-Ci]+Wi( j >= Ci ),  f[i-1,j] }
根据上面的状态转移方程可以写出下面的代码
```c++
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
```

#### 提示
```c++
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
    return 0;
}
```

#### 代码
```c++
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
    return 0;
}
```

---
### 第五步
#### 讲解
最后输出我们想要的结果。在`main`函数里继续写下
```c++
cout << dp[N][V] << endl;
```

#### 提示
```c++
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
```

#### 代码
```c++
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
```


---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
5 10
2 1
3 5
2 5
3 4
4 3
```
