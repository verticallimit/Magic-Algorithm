# hungury 的使用
- hungury

### 文件名
hungury.cpp

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
这一节我们学习二分图的最大匹配问题`hungury`(匈牙利算法)。
二分图：是图论中的一种特殊模型。若能将无向图G=(V,E)的顶点V划分为两个交集为空的顶点集，并且任意边的两个端点都分属于两个集合，则称图G为一个为二分图。
交替路：从一个未匹配点出发，依次经过非匹配边、匹配边、非匹配边...形成的路径叫交替路。
增广路：从一个未匹配点出发，走交替路，如果途径另一个未匹配点（出发的点不算），则这条交替路称为增广路（agumenting path）。
过程：由增广路的性质，增广路中的匹配边总是比未匹配边多一条，所以如果我们放弃一条增广路中的匹配边，选取未匹配边作为匹配边，则匹配的数量就会增加。匈牙利算法就是在不断寻找增广路，如果找不到增广路，就说明达到了最大匹配。
我们先定义好的要用到的数据。在`main`函数上面写下
```c++
bool G[110][110];
bool vis[110];
int link[110];
int n;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来初始化邻接矩阵`G`。
在`main`函数里面写下
```c++
memset(G, false, sizeof(G));
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));

    return 0;
}
```

---
### 第三步
#### 讲解
然后输入图的顶点数`n`和边的条数`m`。
在`main`函数里面继续写下
```c++
int m;
cin >> n >> m;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来输入`m`条边的数据并将连通的两个点的值置为1。
在`main`函数里面写下
```c++
while (m--) {
    int a, b;
    cin >> a >> b;
    G[a][b] = 1;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`match(int u)`函数。
这个过程是在寻找增光路进行匹配。
在`main`函数上面写下
```c++
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


---
### 第六步
#### 讲解
接下来实现`hungury()`函数。
需要对于每个点都去找一下看是否有增广路达到更大的匹配。
在`main`函数上面写下
```c++
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }

    return 0;
}
```


---
### 第七步
#### 讲解
最后调用`hungury()`输出计算结果。
在`main`函数里面写下
```c++
cout << hungury() << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    cout << hungury() << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
bool G[110][110];
bool vis[110];
int link[110];
int n;
bool match(int u) {
    for (int i = 1; i <= n; ++i) {
        if (G[u][i] && !vis[i]) {
            vis[i] = true;
            if (link[i] == -1 || match(link[i])) {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungury() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        ans += match(i);
    }
    return ans;
}

int main() {
    memset(G, false, sizeof(G));
    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    cout << hungury() << endl;
    return 0;
}
```


---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了`hungury算法`了。
