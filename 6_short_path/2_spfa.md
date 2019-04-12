# spfa 的使用
- spfa

### 文件名
spfa.cpp

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
这一节我们学习`spfa`最短路算法。
上一节我们学会了`dijstra`算法求最短路，但是当给定的图存在负权边时，`dijstra`便不适用了，这时`spfa`就能派上用场了。
算法思想：我们用数组`d`记录每个结点的最短路径估计值，用邻接表`E`来存储图。
我们采取的方法是动态逼近法：设立一个先进先出的队列用来保持待优化的节点，优化时每次取出队首节点`u`,并且用`u`点当前的最短路径估计值对离开`u`点所指向的节点`v`进行松弛操作，如果`v`点的最短路径估计值有所调整，且`v`点不在当前队列中，就将`v`点放入队尾。这样不断从队列中取出节点来进行松弛操作，直到队列为空停止。
我们先定义好需要用到的数据。在`main`函数上面写下
```c++
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

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
int n, m;
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

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
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```

---
### 第三步
#### 讲解
然后在`main`函数中初始化邻接表`init();`。在`main`函数里继续写下
```c++
init();
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

int main() {
    int n, m;
    cin >> n >> m;
    init();

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

int main() {
    int n, m;
    cin >> n >> m;
    init();

    return 0;
}
```


---
### 第四步
#### 讲解
然后输入图的`m`条边的权值并存储到邻接表中。
在`main`函数里继续写下
```c++
for (int i = 0; i < m; ++i) {
    int u, v, len;
    cin >> u >> v >> len;
    insert(u, v, len);
    insert(v, u, len);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`init`函数。
在`main`函数上方写下
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来实现邻接表的插入`insert`函数。
在`main`函数里面写下
```c++
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来实现最关键的`spfa(int s)`函数。
算法的核心：
1、用队列维护顶点的先进先出性质
2、松弛操作
在`main`函数上方写下
```c++
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }

    return 0;
}
```

---
### 第八步
#### 讲解
最后我们调用`spfa(1)`计算并输出顶点1到各个点的最短路径距离。
在`main`函数里继续写下
```c++
spfa(1);
for (int i = 1; i <= n; ++i) {
    cout << d[i] << " ";
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }
    spfa(1);
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
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
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}
bool inq[MAX_N];
int d[MAX_N];
void spfa(int s) {
    memset(inq, false, sizeof(inq));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = p[u]; i + 1; i = E[i].next) {
            int v = E[i].v;
            if (d[u] + E[i].len < d[v]) {
                d[v] = d[u] + E[i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        insert(u, v, len);
        insert(v, u, len);
    }
    spfa(1);
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
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
