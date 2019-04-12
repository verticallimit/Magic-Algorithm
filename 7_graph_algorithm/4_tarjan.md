# tarjan 的使用
- tarjan

### 文件名
tarjan.cpp

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
这一节我们学习求图的强连通分量`scc`(tarjan算法实现)。
首先我们引入定义：
1、有向图G中，以顶点v为起点的弧的数目称为v的出度，记做deg+(v),以顶点v为终点的弧的数目称为v的入度，记做deg-(v)。
2、如果在有向图G中，有一条<u，v>有向道路，则v称为u可达的，或者说，从u可达v。
3、如果有向图G的任意两个顶点都互相可达，则称图 G是强连通图，如果有向图G存在两顶点u和v使得u不能到v，或者v不能到u，则称图G是强非连通图。
4、如果有向图G不是强连通图，他的子图G2是强连通图，点v属于G2，任意包含v的强连通子图也是G2的子图，则称G2是有向图G的极大强连通子图，也称强连通分量。
5、什么是强连通? 强连通其实就是指图中有两点u，v。使得能够找到有向路径从u到v并且也能够找到有向路径从v到u，则称u，v是强连通的。
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
然后输入顶点数`n`和边的数量`m`。
在`main`函数里面写下
```c++
int n, m;
init();
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
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
    int n, m;
    init();
    cin >> n >> m;

    return 0;
}
```


---
### 第五步
#### 讲解
接下来输入图的`m`条边。在`main`函数里面写下
```c++
for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    insert(u, v);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
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
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
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
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来用`dfs`遍历这棵树，将各个节点的深度和父节点预处理出来。
在`main`函数里面写下
```c++
memset(dfn, 0, sizeof(dfn));
idx = 0;
for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) {
        tarjan(i);
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
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
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
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
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来实现`tarjan(int u)`函数
在`main`函数上面写下
```c++
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
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
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
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
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    return 0;
}
```


---
### 第八步
#### 讲解
最后我们将计算出的每一个强连通分量所属的点集打印出来。
在`main`函数里面写下
```c++
for (int i = 1; i <= scc; ++i) {
    cout << "block " << i << ": ";
    for (int j = 1; j <= n; ++j) {
        if (belong[j] == i) {
            cout << j << " ";
        }
    }
    cout << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
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
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= scc; ++i) {
        cout << "block " << i << ": ";
        for (int j = 1; j <= n; ++j) {
            if (belong[j] == i) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
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
int dfn[MAX_N], low[MAX_N];
int idx = 0;
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i + 1; i = E[i].next) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            in_stack[s[top]] = false;
        } while (s[top] != u);
    }
}

int main() {
    int n, m;
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    memset(dfn, 0, sizeof(dfn));
    idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= scc; ++i) {
        cout << "block " << i << ": ";
        for (int j = 1; j <= n; ++j) {
            if (belong[j] == i) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`tarjan算法`了。
