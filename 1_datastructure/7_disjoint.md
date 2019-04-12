# disjoint 的使用
- disjoint

### 文件名
disjoint.cpp

### 分数
1

---
### 初始化代码
```c++
#include <iostream>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
首先我们需要定义节点个数`n`，`father`父节点数组，`dist`距离数组，`size`权值数组，在`main`函数上方写下
```c++
int father[110], n;
int dist[110], size[110];
```

#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
然后对这些数组进行初始化。在`main`函数里写下
```c++
n = 10;
init();
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];
int main() {
    n = 10;
    init();

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];
int main() {
    n = 10;
    init();

    return 0;
}
```

---
### 第三步
#### 讲解
接下来具体实现`init`函数。继续在`main`函数上面写下
```c++
void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int main() {
    n = 10;
    init();

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int main() {
    n = 10;
    init();

    return 0;
}
```


---
### 第四步
#### 讲解
现在开始学习并查集的`merge`操作，我们将`1`和`2`、`10`和`7`、`3`和`4`、`3`和`7`合并。在`main`函数里继续写下
```c++
merge(1, 2);
merge(10, 7);
merge(3, 4);
merge(3, 7);
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);

    return 0;
}
```

---
### 第五步
#### 讲解
接下来我们具体实现`merge`函数。在`main`上方继续写下
```c++
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);

    return 0;
}
```




---
### 第六步
#### 讲解
接下来我们查找`1`所在集合的根节点并输出`1`到根节点的距离`dist`。在`main`函数里继续写下
```c++
get(1); // 一定要先 get，可能没有直接连接根节点
cout << dist[1] + 1 << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;

    return 0;
}
```

---
### 第七步
#### 讲解
我们接着实现`get`函数。在`merge`函数上方继续写下
```c++
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
```



#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;

    return 0;
}
```



---
### 第八步
#### 讲解
到这里，里可以点击**运行**看看效果。

接下来我们查找`3`所在集合的根节点并输出`3`到根节点的距离`dist`。在`main`函数里继续写下
```c++
get(3);
cout << dist[3] + 1 << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;
    get(3);
    cout << dist[3] + 1 << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;
    get(3);
    cout << dist[3] + 1 << endl;
    return 0;
}
```




---
### 完成讲解
这一节已经完成了，赶紧运行看看效果。

聪明的你一定学会了`disjoint`怎么用了。
