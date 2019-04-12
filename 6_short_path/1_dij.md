# dij 的使用
- dij

### 文件名
dij.cpp

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
这一节我们学习`dijstra`最短路算法。
算法的基本思想是：设G=(V,E)是一个带权有向图，把图中顶点集合V分成两组，第1组为已求出最短路径的顶点集合(用S表示，初始时S中只有一个源点，以后每求得一条最短路径v,...k,就将k加入到集合S中，直到全部顶点都加入到S中，算法结束)，第2组为其余未确定最短路径的顶点集合(用U表示)，按最短路径长度的递增次序依次把第2组的顶点加入到S中。
我们先定义好需要用到的数据。在`main`函数上面写下
```c++
const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来我们输入顶点个数`n`和边的数量`m`。
在`main`函数里面写下
```c++
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;

    return 0;
}
```

---
### 第三步
#### 讲解
然后在`main`函数中初始化邻接矩阵`G`。在`main`函数里继续写下
```c++
memset(G, 0x3f, sizeof(G));
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));

    return 0;
}
```


---
### 第四步
#### 讲解
然后输入图的`m`条边的权值并存储到邻接矩阵中。
在`main`函数里继续写下
```c++
for (int i = 0; i < m; ++i) {
    int u, v, len;
    cin >> u >> v >> len;
    G[u][v] = G[v][u] = len;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;

int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现最关键的`dijkstra(int s)`函数。
算法的核心分为两步：
1、在U集合中找到一个距离S集合最短距离的顶点然后加入S
2、更新S到所有顶点的最短距离
在`main`函数上方写下
```c++
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来调用`dijkstra(1);`计算从顶点1出发的最短路径长度。
在`main`函数里面写下
```c++
dijkstra(1);
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    dijkstra(1);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    dijkstra(1);

    return 0;
}
```


---
### 第七步
#### 讲解
最后输出顶点1到每个顶点的最短路径长度。
在`main`函数里面写下
```c++
for (int i = 1; i <= n; ++i) {
    cout << dist[i] << " ";
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[110][110];
int dist[110];
bool vst[110];
int n, m;
void dijkstra(int s) {
    memset(vst, false, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int v, min_d = inf;
        for (int j = 1; j <= n; ++j) {
            if (!vst[j] && dist[j] < min_d) {
                min_d = dist[j];
                v = j;
            }
        }
        vst[v] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[v] + G[v][j]);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
5 6
1 2 3
2 3 2
3 4 1
2 4 10
4 5 1
1 3 7
```
