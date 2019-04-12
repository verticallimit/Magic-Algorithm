# cost_flow 的使用
- cost_flow

### 文件名
cost_flow.cpp

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
这一节我们学习网络流的`cost_flow`算法求图的最小费用流。
通过`dinic`算法可以得到网络流图中的最大流，一个网络流图中最大流的流量max_flow是唯一的，但是达到最大流量max_flow时每条边上的流量分配f是不唯一的。
如果给网络流图中的每条边都设置一个费用cost，表示单位流量流经该边时会导致花费cost。那么在这些流量均为max_flow的流量分配f中，存在一个流量总花费最小的最大流方案。
即 min{sum(cost(i, j) * f(i,j) | (i, j)属于方案f中的边， f(i,j)为 边(i,j)上的流量， f为某一个最大流方案}。此即为最小费用最大流。
我们先定义好的要用到的数据。在`main`函数上面写下
```c++
const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;

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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
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
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
然后实现`addedge(int u, int v, int c, int w)`增加边的函数。
在`main`函数上面写下
```c++
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
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
    int u, v, c, w;
    cin >> u >> v >> c >> w;
    addedge(u, v, c, w);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
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

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来输入源点`s`和汇点`t`。
在`main`函数里面写下
```c++
cin >> s >> t;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


---
### 第八步
#### 讲解
算法思想
采用贪心的思想，每次找到一条从源点到达汇点的路径，增加流量，且该条路径满足使得增加的流量的花费最小，直到无法找到一条从源点到达汇点的路径，算法结束。
由于最大流量有限，每执行一次循环流量都会增加，因此该算法肯定会结束，且同时流量也必定会达到网络的最大流量；同时由于每次都是增加的最小的花费，即当前的最小花费是所有到达当前流量flow时的花费最小值，因此最后的总花费最小。
求解步骤
（1）找到一条从源点到达汇点的“距离最短”的路径，“距离”使用该路径上的边的单位费用之和来衡量。
（2）然后找出这条路径上的边的容量的最小值f，则当前最大流max_flow扩充f，同时当前最小费用min_cost扩充 f * min_dist(s,t)。
（3）将这条路径上的每条正向边的容量都减少f，每条反向边的容量都增加f。
（4）重复（1）--（3）直到无法找到从源点到达汇点的路径。
在`main`函数上面写下
```c++
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


---
### 第九步
#### 讲解
接下来实现`costflow()`函数。
在`main`函数上面写下
```c++
int costflow() {
    int ret = 0;
    while(spfa()) {
        int flow = inf;
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            flow = min(e[pre[i]].c, flow);
        }
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            e[pre[i]].c -= flow;
            e[pre[i]^1].c += flow;
            ret += e[pre[i]].w * flow;
        }
    }
    return ret;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}
int costflow() {
    int ret = 0;
    while(spfa()) {
        int flow = inf;
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            flow = min(e[pre[i]].c, flow);
        }
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            e[pre[i]].c -= flow;
            e[pre[i]^1].c += flow;
            ret += e[pre[i]].w * flow;
        }
    }
    return ret;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}
int costflow() {
    int ret = 0;
    while(spfa()) {
        int flow = inf;
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            flow = min(e[pre[i]].c, flow);
        }
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            e[pre[i]].c -= flow;
            e[pre[i]^1].c += flow;
            ret += e[pre[i]].w * flow;
        }
    }
    return ret;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;

    return 0;
}
```


---
### 第十步
#### 讲解
最后调用` costflow()`输出所求的最小费用流的结果。
在`main`函数里面写下
```c++
cout << costflow() << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}
int costflow() {
    int ret = 0;
    while(spfa()) {
        int flow = inf;
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            flow = min(e[pre[i]].c, flow);
        }
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            e[pre[i]].c -= flow;
            e[pre[i]^1].c += flow;
            ret += e[pre[i]].w * flow;
        }
    }
    return ret;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;
    cout << costflow() << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, c, w, next;
} e[MAX_M];
int p[MAX_N], s, t, eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c, int w) {
    e[eid].v = v;
    e[eid].c = c;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void addedge(int u, int v, int c, int w) {
    insert(u, v, c, w);
    insert(v, u, 0, -w);
}
bool inq[MAX_N];
int d[MAX_N];
int pre[MAX_N];
bool spfa() {
    memset(inq, 0, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            if (e[i].c) {
                int v = e[i].v;
                if (d[u] + e[i].w < d[v]) {
                    d[v] = d[u] + e[i].w;
                    pre[v] = i;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
    return pre[t] != -1;
}
int costflow() {
    int ret = 0;
    while(spfa()) {
        int flow = inf;
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            flow = min(e[pre[i]].c, flow);
        }
        for(int i = t; i != s; i = e[pre[i]^1].v) {
            e[pre[i]].c -= flow;
            e[pre[i]^1].c += flow;
            ret += e[pre[i]].w * flow;
        }
    }
    return ret;
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        addedge(u, v, c, w);
    }
    cin >> s >> t;
    cout << costflow() << endl;
    return 0;
}
```


---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`cost_flow算法`了。
