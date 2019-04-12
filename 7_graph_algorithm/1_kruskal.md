# kruskal 的使用
- kruskal

### 文件名
kruskal.cpp

### 分数
1

---
### 初始化代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
这一节我们学习最小生成树`kruskal`算法。
克鲁斯卡尔(kruskal)算法是一种按权值的递增次序选择合适的边来构造最小生成树的方法。
假设G=(V,E)是一个具有n个顶点的带权连通无向图，T=(U,TE)是G的最小生成树，则构造最小生成树的步骤如下：
1、置U的初始值等于V(即包含G中的全部顶点)，TE的初始值为空集(即图T中每一个顶点都构成一个分量)。
2、将图G中的边按权值从小到大的顺序依次选取，若选取的边未使生成树T形成回路，则加入TE，否则舍弃，直到TE中包含(n-1)条边为止。
我们先定义好的要用到的数据。在`main`函数上面写下
```c++
const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
```

#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来输入节点数`n`和`m`条边。
在`main`函数里面写下
```c++
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;

    return 0;
}
```

---
### 第三步
#### 讲解
然后输入`m`条边的数据。在`main`函数里继续写下
```c++
for (int i = 0; i < m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w;
}
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    return 0;
}
```


---
### 第四步
#### 讲解
将`m`条边按权值从小到大排序。
在`main`函数上方写下
```c++
sort(e, e + m);
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);

    return 0;
}
```


---
### 第五步
#### 讲解
接下来初始化并查集。在`main`函数里面写下
```c++
for (int i = 1; i <= n; ++i) {
    fa[i] = i;
}
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来实现并查集的查询`get`操作。
注意：按照深度优先遍历的过程我们需要用队列的先进先出的性质来维护遍历时的顺序。
在`main`函数上面写下
```c++
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    return 0;
}
```


---
### 第七步
#### 讲解
实现`kruskal`算法的关键是判断选取的边是否与生成树中已保留的边形成回路,这可通过判断边的两个顶点所在的连通分量来解决。
在`main`函数里面写下
```c++
int sum = 0;
for (int i = 0; i < m; ++i) {
    int x = get(e[i].u), y = get(e[i].v);
    if (x != y) {
        fa[x] = y;
        sum += e[i].w;
    }
}
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x = get(e[i].u), y = get(e[i].v);
        if (x != y) {
            fa[x] = y;
            sum += e[i].w;
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x = get(e[i].u), y = get(e[i].v);
        if (x != y) {
            fa[x] = y;
            sum += e[i].w;
        }
    }

    return 0;
}
```


---
### 第八步
#### 讲解
最后输出所求最小生成树的值。
在`main`函数里面写下
```c++
cout << sum << endl;
```

#### 提示
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x = get(e[i].u), y = get(e[i].v);
        if (x != y) {
            fa[x] = y;
            sum += e[i].w;
        }
    }
    cout << sum << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} e[MAX_M];

int fa[MAX_N], n, m;
int get(int x) {
    if(fa[x] == x) {
        return fa[x];
    }
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x = get(e[i].u), y = get(e[i].v);
        if (x != y) {
            fa[x] = y;
            sum += e[i].w;
        }
    }
    cout << sum << endl;
    return 0;
}
```




---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
4 5
1 2 3
2 4 7
1 4 2
3 1 4
2 3 3
```
