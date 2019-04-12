# floyd 的使用
- floyd

### 文件名
floyd.cpp

### 分数
1

---
### 初始化代码
```c++
#include <iostream>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
这一节我们学习`floyd`最短路算法。
问题：对于一个各边权值均大于零的有向图，对每一对顶点i!=j,求出顶点i和j之间的最短路径和最短路径长度。
可以通过以每个顶点作为源点循环求出每队顶点之间的最短路径。除此之外，也可用弗洛伊德(Floyd)算法求两顶点之间的最短路径。
我们先定义好需要用到的数据。在`main`函数上面写下
```c++
const int inf = 0x3f3f3f3f;
int G[110][110];
int n;
```

#### 代码
```c++
#include <iostream>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int n;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来我们输入顶点个数`n`和每对顶点之间的距离长度。
在`main`函数里面写下
```c++
cin >> n;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cin >> G[i][j];
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }

    return 0;
}
```

---
### 第三步
#### 讲解
接下来实现最关键的`floyd()`函数。
弗洛伊德（Floyd）算法过程：
１、用`G[i][j]`记录每一对顶点的最短距离。
２、依次扫描每一个点，并以其为基点再遍历所有每一对顶点`G[i][j]`的值，看看是否可用过该基点让这对顶点间的距离更小。
从i号顶点到j号顶点只经过前k号点的最短路程。其实这是一种`动态规划`的思想。
在`main`函数上面继续写下
```c++
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
```

#### 提示
```c++
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

    return 0;
}
```


#### 代码
```c++
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

    return 0;
}
```


---
### 第四步
#### 讲解
然后调用`floyd`函数。
在`main`函数里继续写下
```c++
floyd();
```

#### 提示
```c++
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

    return 0;
}
```


#### 代码
```c++
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

    return 0;
}
```


---
### 第五步
#### 讲解
最后输出每一对顶点之间的最短路径长度。
在`main`函数里继续写下
```c++
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cout << G[i][j] << " ";
    }
    cout << endl;
}
```

#### 提示
```c++
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
```


#### 代码
```c++
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
```


---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
4
0 3 1 4
1 0 3 5
10 2 0 7
1 2 3 0
```
