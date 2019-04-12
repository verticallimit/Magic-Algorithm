# dinic 的使用
- dinic

### 文件名
dinic.cpp

### 分数
1

---
### 初始化代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
这一节我们学习网络流的`dinic`算法求图的最大流。
残留网络：设有容量网络G(V,E)及其上的网络流f，G关于f的残留网络即为G(V',E')，其中G’的顶点集V'和G的顶点集V相同，即V'=V，对于G中任何一条弧<u,v>,如果f(u,v)<c(u,v)，那么在G'中有一条弧<u,v>∈E'，其容量为c'(u,v)=c(u,v)-f(u,v)，如果f(u,v)>0,则在G'中有一条弧<v,u>∈E'，其容量为c’(v,u)=f(u,v)。
从残留网络的定义来看，原容量网络中的每条弧在残留网络中都化为一条或者两条弧。在残留网络中，从源点到汇点的任意一条简单路径都对应一条增光路，路径上每条弧容量的最小值即为能够一次增广的最大流量。
我们先定义好的要用到的数据。在`main`函数上面写下
```c++
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来初始化邻接表。
在`main`函数上面写下
```c++
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}

int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}

int main() {

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现插入邻接表`insert`函数。
在`main`函数上面继续写下
```c++
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
然后实现`addedge(int u, int v, int c)`增加边的函数。
在`main`函数上面写下
```c++
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {

    return 0;
}
```


---
### 第五步
#### 讲解
接下来输入图的顶点数`n`和边的数量`m`。在`main`函数里面写下
```c++
int n, m;
init();
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输入图的m条边的数据。
在`main`函数里面继续写下
```c++
for (int i = 0; i < m; ++i) {
    int u, v, flow;
    cin >> u >> v >> flow;
    addedge(u, v, flow);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来输入源点`S`和汇点`T`。
在`main`函数里面写下
```c++
cin >> S >> T;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


---
### 第八步
#### 讲解
接下来实现`bfs()`函数进行层次遍历。
在`main`函数上面写下
```c++
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


---
### 第九步
#### 讲解
接下来实现`dfs(int u, int flow)`函数。
最短增广路的算法思想是：每次在层次网络中找一条含弧数最少的增广路进行增广。最短增广路算法的具体步骤如下：
（1）初始化容量网络和网络流。
（2）构造残留网络和层次网络，若汇点不在层次网络中，则算法结束。
（3）在层次网络中不断用BFS增广，直到层次网络中没有增广路为止；每次增广完毕，在层次网络中要去掉因改进流量而导致饱和的弧。
（4）转步骤（2）。
在`main`函数上面写下
```c++
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


---
### 第十步
#### 讲解
接下来实现`dinic()`函数。
在`main`函数上面写下
```c++
int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}
int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}
int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;

    return 0;
}
```


---
### 第十一步
#### 讲解
最后调用`dinic()`计算出网络最大流结果。
在`main`函数里面写下
```c++
cout << dinic() << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}
int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;
    cout << dinic() << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, c, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].c = c;
    p[u] = eid++;
}
void addedge(int u, int v, int c) {
    insert(u, v, c);
    insert(v, u, 0);
}
int S, T;
int d[MAX_N];
bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].c > 0 && d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (d[T] != -1);
}
int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = 0;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].c > 0 && d[u] + 1 == d[v]) {
            int tmp = dfs(v, min(flow, e[i].c));
            flow -= tmp;
            e[i].c -= tmp;
            res += tmp;
            e[i ^ 1].c += tmp;
            if (flow == 0) {
                break;
            }
        }
    }
    if (res == 0) {
        d[u] = -1;
    }
    return res;
}
int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(S, INF);
    }
    return res;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, flow;
        cin >> u >> v >> flow;
        addedge(u, v, flow);
    }
    cin >> S >> T;
    cout << dinic() << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`dinic算法`了。
