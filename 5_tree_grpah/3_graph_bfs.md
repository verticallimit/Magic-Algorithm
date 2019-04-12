# graph_bfs 的使用
- graph_bfs

### 文件名
graph_bfs.cpp

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
这一节我们学习图的广度优先遍历（BFS）算法。
广度优先遍历的过程是：首先访问初始顶点v，接着访问顶点v的所有未被访问过的邻接点v1,v2,v3...,然后再按照v1,v2,v3...的次序，访问每一个顶点的所有未被访问过的邻接点，依次类推，知道图中所有的初始顶点v有路径相通的顶点都被访问过为止。
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
然后在`main`函数中调用初始化邻接表的函数。在`main`函数里继续写下
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
接下来我们要实现`bfs`函数。
注意：按照深度优先遍历的过程我们需要用队列的先进先出的性质来维护遍历时的顺序。
在`main`函数上面写下
```c++
bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
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

bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
            }
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

bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
            }
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
最后在`main`函数里调用`bfs(1)`，以顶点`1`作为起点进行深度优先遍历。
在`main`函数里面写下
```c++
bfs(1);
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

bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
            }
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
    bfs(1);
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

bool vst[MAX_N];
void bfs(int v) {
    memset(vst, false, sizeof(vst));
    queue<int> q;
    q.push(v);
    vst[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visiting " << u << endl;
        for (int i = p[u]; i + 1; i = E[i].next) {
            if (!vst[E[i].v]) {
                vst[E[i].v] = 1;
                q.push(E[i].v);
            }
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
    bfs(1);
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`bfs`了。
