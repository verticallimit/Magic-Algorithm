# graph_dfs 的使用
- graph_dfs

### 文件名
graph_dfs.cpp

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
这一节我们学习图的深度优先遍历（DFS）算法。
深度优先遍历的过程是：从图中某个初始顶点v出发，首先访问初始顶点v，然后选择一个与顶点v相邻且没被访问过的顶点w为初始顶点，再从w出发进行深度优先遍历，直到图中与当前顶点v邻接的所有顶点都被访问过为止。
显然，这个遍历过程是个递归过程。
我们先定义好邻接表的结构。在`main`函数上面写下
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
接下来我们初始化邻接表。
定义一个`init`函数。
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
然后在`main`函数中调用初始化邻接表的函数。在`main`函数里继续写下
```c++
init();
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
    init();

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
    init();

    return 0;
}
```


---
### 第四步
#### 讲解
接下来实现邻接表的插入操作`insert`函数。
在`main`函数上方写下
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
    init();

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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {
    init();

    return 0;
}
```


---
### 第五步
#### 讲解
接下来就可以插入图的边了。在`main`函数里面写下
```c++
insert(1, 2, 10);
insert(1, 3, 5);
insert(2, 3, 1);
insert(3, 5, 10);
insert(3, 4, 6);
insert(5, 4, 11);
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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);

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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);

    return 0;
}
```


---
### 第六步
#### 讲解
接下来我们要实现`dfs`函数。
在`main`函数上面写下
```c++
bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
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

bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
            dfs(E[i].v);
        }
    }
}
int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);

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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
            dfs(E[i].v);
        }
    }
}
int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);

    return 0;
}
```


---
### 第七步
#### 讲解
最后在`main`函数里初始化`vst`标记数组并以顶点`1`作为起点进行深度优先遍历。
在`main`函数里面写下
```c++
memset(vst, false, sizeof(vst));
dfs(1);
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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
            dfs(E[i].v);
        }
    }
}
int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);
    memset(vst, false, sizeof(vst));
    dfs(1);

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
void insert(int u, int v, int len) {
    E[eid].v = v;
    E[eid].len = len;
    E[eid].next = p[u];
    p[u] = eid++;
}

bool vst[MAX_N];
void dfs(int u) {
    cout << "visiting " << u << endl;
    vst[u] = true;
    for (int i = p[u]; i + 1; i= E[i].next) {
        if (!vst[E[i].v]) {
            dfs(E[i].v);
        }
    }
}
int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);
    memset(vst, false, sizeof(vst));
    dfs(1);

    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`dfs`了。
