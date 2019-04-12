# queen 模板
- queen

### 文件名
queen.cpp

### 分数
1


---
### 初始化代码
```c++
#include <iostream>
#include <cstring>
using namespace std;

int n;
bool flag = 0;
int G[20][20];

int main() {
    cin >> n;

    return 0;
}
```

---
### 第一步
#### 讲解
通过本节课，我们来用 dfs 算法来解决一个实际问题——N皇后问题。

N皇后问题是一个经典的问题，在一个N*N的棋盘上放置N个皇后，每行一个并使其不能互相攻击（同一行、同一列、同一斜线上的皇后都会自动攻击）。

我们先定义一些标记数组。在`main`函数的上方写下

```c++
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
```

#### 提示
```c++
#include <iostream>
#include <cstring>
using namespace std;

int n;
bool flag = 0;
int G[20][20];
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
int main() {
    cin >> n;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <cstring>
using namespace std;

int n;
bool flag = 0;
int G[20][20];
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
int main() {
    cin >> n;

    return 0;
}
```


---
### 第二步
#### 讲解
下面我们要将刚刚定义的标记数组初始化。在`main`函数里写下

```c++
memset(a, false, sizeof(a));
memset(x1, false, sizeof(x1));
memset(y1, false, sizeof(y1));
memset(G, 0, sizeof(G));
```



#### 提示
```c++
#include <iostream>
#include <cstring>
using namespace std;

int n;
bool flag = 0;
int G[20][20];
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstring>
using namespace std;

int n;
bool flag = 0;
int G[20][20];
bool a[20];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[20];  // 左下-右上 对角线的占用情况
bool y1[20];  // 左上-右下 对角线的占用情况
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们要实现一个dfs的函数框架，`flag`为1表示已经搜到了一个符合要求的N皇后。在`main`函数上面继续写下
```c++
void dfs(int deep) {
    if (flag == 1) {
        return;
    }
}
```

#### 提示
```c++
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
}
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```


#### 代码
```c++
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
}
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```


---
### 第四步
#### 讲解
当搜索的深度`deep`大于等于n时，说明已经搜索完了，这时输出我们搜索到的结果并把`flag`标记设置为1。在`dfs`函数里面写下
```c++
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
```

#### 提示
```c++
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
}
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```

#### 代码
```c++
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
}
int main() {
    cin >> n;
    memset(a, false, sizeof(a));
    memset(x1, false, sizeof(x1));
    memset(y1, false, sizeof(y1));
    memset(G, 0, sizeof(G));

    return 0;
}
```

---
### 第五步
#### 讲解
接下来我们遍历每一列看是否可以继续放皇后，如果可以那么`dfs(deep + 1)`。在`dfs`函数里继续写下
```c++
for (int i = 0; i < n; i++) {
    if (x1[i + deep] == false && y1[i - deep + n] == false && a[i] == false) {
        dfs(deep + 1);
    }
}
```
注意标记数组在dfs前后的`true`和`false`的转化。当出了dfs一定要记得还原标记，否则会影响下一次dfs的结果。
```c++
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
```

#### 提示
```c++
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

    return 0;
}
```

#### 代码
```c++
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

    return 0;
}
```

---
### 第六步
#### 讲解
最后在`main`加上`dfs`函数的调用。继续写下
```c++
dfs(0);
```

#### 提示
```c++
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
```

#### 代码
```c++
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
```



---
### 完成讲解
终于完成了，点击运行，输入8看看效果吧。

聪明的你一定学会了`dfs`怎么用了。
