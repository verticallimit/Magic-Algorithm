# LCS 模板
- LCS

### 文件名
LCS.cpp

### 分数
1


---
### 初始化代码
```c++
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
通过本节课，我们用动态规划算法来解决一个实际问题——最长公共子序列问题。

最长公共子序列（LCS）是一个在一个序列集合中（通常为两个序列）用来查找所有序列中最长子序列的问题。一个数列 ，如果分别是两个或多个已知数列的子序列，且是所有符合此条件序列中最长的，则称为已知序列的最长公共子序列。

我们先定义一个辅助数组。在`main`函数的上方写下

```c++
int dp[110][110];
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int dp[110][110];
int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int dp[110][110];
int main() {

    return 0;
}
```


---
### 第二步
#### 讲解
下面我们要输入两个字符串`a`和`b`并将`dp`数组初始化。在`main`函数里写下

```c++
string a, b;
memset(dp, 0, sizeof(dp));
cin >> a >> b;
```



#### 提示
```c++
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int dp[110][110];
int main() {
    string a, b;
    memset(dp, 0, sizeof(dp));
    cin >> a >> b;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int dp[110][110];
int main() {
    string a, b;
    memset(dp, 0, sizeof(dp));
    cin >> a >> b;

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们计算出字符串`a`和`b`的长度。
继续写下
```c++
int lena = a.size();
int lenb = b.size();
```

#### 提示
```c++
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

    return 0;
}
```


#### 代码
```c++
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

    return 0;
}
```


---
### 第四步
#### 讲解
接下来我们分析算法的状态转移方程。
dp[i, j]代表a字符串前i个字符组成的子串和b字符串前j个字符组成的子串的LCS。
那么
dp[i, j] = 0  if i = 0 or j = 0
dp[i, j] = dp[i - 1, j - 1] + 1  if i, j > 0 and ai = bj
dp[i, j] = max{dp[i, j - 1], dp[i - 1, j]}  if i, j > 0 and ai != bj
根据上面的状态转移方程可以写出一下代码
```c++
for(int i = 1; i <= lena; ++i) {
    for (int j = 1; j <= lenb; ++j) {
        if(a[i - 1] == b[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
```

#### 提示
```c++
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

    return 0;
}
```

#### 代码
```c++
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

    return 0;
}
```

---
### 第五步
#### 讲解
最后我们输出要求解的LCS值。在`main`函数里面继续写下
```c++
cout << dp[lena][lenb] << endl;
```

#### 提示
```c++
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
```

#### 代码
```c++
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
```


---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
abcdefgh
acjlfabhh
```
