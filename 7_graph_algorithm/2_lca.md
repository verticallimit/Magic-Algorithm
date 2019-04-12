# lca 的使用
- lca

### 文件名
lca.cpp

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
这一节我们学习最近公共祖先`lca`(倍增算法实现)。
在一棵没有环的树上，每个节点肯定有其父亲节点和祖先节点，而最近公共祖先，就是两个节点在这棵树上深度最大的公共的祖先节点。
倍增算法是在线算法，简单来说我们要求a和b的最近公共祖先可以分为两步。
1、如果a和b的深度不同，先把深的调浅，使他变得和浅的那个一样
2、现在已经保证了a和b的深度一样，所以我们只要把两个一起一步一步往上移动，直到他们到达同一个节点，也就是他们的最近公共祖先了。
我们先定义好的要用到的数据。在`main`函数上面写下
```c++
const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
} E[MAX_M];
int p[MAX_N], eid;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
然后输入节点数`n`并调用`init`函数。
在`main`函数里面写下
```c++
int n;
init();
cin >> n;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
    int n;
    init();
    cin >> n;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
    int n;
    init();
    cin >> n;

    return 0;
}
```


---
### 第五步
#### 讲解
接下来输入树的`n-1`条边。在`main`函数里面写下
```c++
for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    insert(u, v);
    insert(v, u);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来用`dfs`遍历这棵树，将各个节点的深度和父节点预处理出来。
在`main`函数上面写下
```c++
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}

int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}

int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来我们用倍增的思想进行预处理。
fa[i][j]表示节点i往上走2^j次所到达的祖先，那么不难写出转移方程：
fa[i][0]=father[i]
fa[i][j]=fa[fa[i][j-1]][j-1]
在`main`函数里面写下
```c++
memset(d, -1, sizeof(d));
dfs(1);
for (int level = 1; (1 << level) <= n; level++) {
    for (int i = 1; i <= n; i++) {
        fa[i][level] = fa[fa[i][level - 1]][level - 1];
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}

int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}

int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
        }
    }

    return 0;
}
```


---
### 第八步
#### 讲解
接下来要实现查询`lca(int x, int y)`的函数。
1.把a和b移到同一深度（d[x]为节点x的深度），假设d[a]<=d[b],所以我们的目的是把b向上移动i=(d[b]-d[a])层，那么，由于之前有预处理的fa数组，我们把i写成二进制形式，然后利用fa数组来在`log(n)`的复杂度中完成；
2.寻找a和b的LCA下一层的两个祖先。利用之前的那个性质，再利用倍增，如果a和b的第2^k个祖先不是同一个，那么把a改为fa[a][k],b改为fa[b][k],k减1;否则直接k减1；当然在这之前要实现确定k的最大值，从大往小处理下去。最终的结果就是fa[a][0]或者fa[b][0]。
在`main`函数上面写下
```c++
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
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

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
        }
    }

    return 0;
}
```


---
### 第九步
#### 讲解
最后输入`q`个查询，计算`a`和`b`的最近公共祖先。
在`main`函数里面写下
```c++
int q;
cin >> q;
while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lca(a, b) << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

struct edge {
    int v, next;
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
int d[MAX_N], fa[MAX_N][20];
void dfs(int u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        if (d[E[i].v] == -1) {
            d[E[i].v] = d[u] + 1;
            fa[E[i].v][0] = u;
            dfs(E[i].v);
        }
    }
}
int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++);
    --i;
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    memset(d, -1, sizeof(d));
    dfs(1);
    for (int level = 1; (1 << level) <= n; level++) {
        for (int i = 1; i <= n; i++) {
            fa[i][level] = fa[fa[i][level - 1]][level - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
```




---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`lca倍增算法`了。
