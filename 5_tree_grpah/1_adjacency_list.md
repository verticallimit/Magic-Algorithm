# adjacency_list 的使用
- adjacency_list

### 文件名
adjacency_list.cpp

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
这一节我们学习图的邻接表存储方法。
图的邻接表存储方法是一种顺序分配与链式分配相结合的存储方法。
在表示含n个顶点的图的邻接表中，为每个顶点建立一个单链表，第i个单链表中的节点表示依附于顶点i的边（对有向图是以顶点i为尾的边）。每个单链表上附设一个表头节点，将所有表头节点构成一个表头节点数组。
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
注意：`p`数组是表头节点，然后`E`中存储的边采用的头插法。
可以理解为用数组实现哈希冲突中的拉链法的感觉。
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
接下来我们要输出刚才使用邻接表方法插入的边。
在`main`函数里继续写下
```c++
for (int u = 1; u <= 5; ++u) {
    for (int i = p[u]; i + 1; i = E[i].next) {
        cout << "(" << u << ", " << E[i].v << ")" << endl;
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

int main() {
    init();
    insert(1, 2, 10);
    insert(1, 3, 5);
    insert(2, 3, 1);
    insert(3, 5, 10);
    insert(3, 4, 6);
    insert(5, 4, 11);
    for (int u = 1; u <= 5; ++u) {
        for (int i = p[u]; i + 1; i = E[i].next) {
            cout << "(" << u << ", " << E[i].v << ")" << endl;
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
    for (int u = 1; u <= 5; ++u) {
        for (int i = p[u]; i + 1; i = E[i].next) {
            cout << "(" << u << ", " << E[i].v << ")" << endl;
        }
    }
    return 0;
}
```


---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`邻接表`了。
