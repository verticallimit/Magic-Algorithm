# topsort 的使用
- topsort

### 文件名
topsort.cpp

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
这一节我们学习求图的拓扑排序。
设G=(V,E)是一个具有n个顶点的有向图，V中顶点序列v1,v2,...,vn为一个拓扑序列当且仅当该点序列满足下列条件：
若<vi,vj>是图中的边(即从顶点vi到顶点vj有一条路径),则在序列中顶点vi必须排在顶点vj之前。
在一个有向图中找一个拓扑序列的过程称为拓扑排序。
我们先定义好的要用到的数据。在`main`函数上面写下
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

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现插入邻接表`insert`函数。
在`main`函数上面继续写下
```c++
void insert(int u, int v) {
    E[eid].v = v;
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
定义顶点数量`n`和边的数量`m`以及入度数组。
在`main`函数上方写下
```c++
int n, m;
int indegree[MAX_N];
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

int main() {

    return 0;
}
```


---
### 第五步
#### 讲解
初始化操作以及输入`n`和`m`的值。在`main`函数里面写下
```c++
init();
memset(indegree, 0, sizeof(indegree));
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
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
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
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输入m条边并相应的增加入度数量。
在`main`函数里面写下
```c++
for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    insert(u, v);
    ++indegree[v];
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来实现`topo()`函数。
拓扑排序的方法如下：
1、从有向图中选择一个没有前驱(即入度为0)的顶点并且输出它
2、从图中删去该顶点，并且删去从该顶点出发的全部有向边
3、重复上述两步，直到图中不再存在没有前驱的顶点为止
在`main`函数上方写下
```c++
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
    }

    return 0;
}
```


---
### 第八步
#### 讲解
最后调用`topsort`函数计算出结果。
在`main`函数里面写下
```c++
topo();
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
    }
    topo();
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
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n, m;
int indegree[MAX_N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        cout << now << endl;
        q.pop();
        for (int i = p[now]; i + 1; i = E[i].next) {
            int v = E[i].v;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        ++indegree[v];
    }
    topo();
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`拓扑排序算法`了。
