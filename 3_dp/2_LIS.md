# LIS 模板
- LIS

### 文件名
LIS.cpp

### 分数
1


---
### 初始化代码
```c++
// n^2 和 nlgn 的最长上升子序列

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
通过本节课，我们用动态规划算法来解决一个实际问题——最长上升子序列问题。

最长上升子序列(Longest Increasing Subsequence, 简称LIS)是dp中比较经典的一个算法模型, 它有一种朴素的算法O(n^2)和一种优化版的算法O(nlogn)实现, 通过它, 我们可以进一步了解dp的思想.

我们先定义一些辅助数组。在`main`函数的上方写下

```c++
int dp[101], a[101], n;
```

#### 提示
```c++
// n^2 和 nlgn 的最长上升子序列

#include <iostream>
#include <string.h>

using namespace std;
int dp[101], a[101], n;

int main() {

    return 0;
}
```

#### 代码
```c++
// n^2 和 nlgn 的最长上升子序列

#include <iostream>
#include <string.h>

using namespace std;
int dp[101], a[101], n;

int main() {

    return 0;
}
```


---
### 第二步
#### 讲解
下面我们要输入总个数N和N个数。在`main`函数里写下

```c++
cin >> n;
for (int i = 1; i <= n; ++i) {
    cin >> a[i];
}
```



#### 提示
```c++
// n^2 和 nlgn 的最长上升子序列

#include <iostream>
#include <string.h>

using namespace std;
int dp[101], a[101], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    return 0;
}
```


#### 代码
```c++
// n^2 和 nlgn 的最长上升子序列

#include <iostream>
#include <string.h>

using namespace std;
int dp[101], a[101], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们实现O(n^2)的算法`LIS_nn()`。
首先确定状态转移方程
dp[i]代表以第i项为结尾的LIS的长度
dp[i] = max(dp[i], max(dp[j]) + 1) if j < i and a[j] < a[i]
根据上面的状态转移方程可以写出下面的代码
```c++
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
```

#### 提示
```c++
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    return 0;
}
```


#### 代码
```c++
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    return 0;
}
```


---
### 第四步
#### 讲解
接下来输出刚才算法的结果。在`main`函数里继续写下
```c++
cout << LIS_nn() << endl;
```

#### 提示
```c++
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << LIS_nn() << endl;

    return 0;
}
```

#### 代码
```c++
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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << LIS_nn() << endl;

    return 0;
}
```

---
### 第五步
#### 讲解
我们继续思考一下刚才的算法是否还有优化的空间呢？
在刚才的内层for我们从前往后找一个最大的LIS值，仔细想一下是否可以发现这个值一定是单调递增的呢?
由于这个值是单调递增的，所以我们就没必要使用从前往后遍历的方法，可以使用二分查找来优化这个寻找的过程。
于是可以实现O(nlogn)算法的`LIS_nlgn()`函数。
在`main`函数上面继续写下
```c++
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
```

#### 提示
```c++
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

    return 0;
}
```

#### 代码
```c++
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

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输出刚才算法的结果。在`main`函数里继续写下
```c++
cout << LIS_nlgn() << endl;
```

#### 提示
```c++
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
```

#### 代码
```c++
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
```

---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
6
3 2 6 1 4 5
```
