# segment_tree_interval 的使用
- segment_tree_interval

### 文件名
segment_tree_interval.cpp

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
这一节我们学习线段树（区间更新）算法。
线段树，就是一颗由线段构成的二叉树，每个节点都代表一条线段[a, b]。
非叶子的节点所对应的线段都有两个子节点，做儿子代表的线段为[a, (a + b) / 2]，右儿子代表的线段为[(a + b) / 2, b]。
使用线段树这一数据结构，可以查找一个连续区间中节点的信息，也可以修改一个连续区间中节点的信息。
换句话说，线段树将优化区间操作的复杂度。
我们先定义要用的数据。在`main`函数上面写下
```c++
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
```

#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来我们实现`up(int p)`函数。
合并左右两个子节点的区间。
在`main`函数上面写下
```c++
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}

int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}

int main() {

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现`down(int p, int l, int r)`函数。
单点更新和区间更新最大的区别就在于向下更新的时候单点是直接更新到最低端而区间更新使用延迟更新的思想提高效率。
在`main`函数上面继续写下
```c++
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
然后实现`modify(int p, int l, int r, int x, int v)`函数。
修改区间上的某个节点区间值。
在`main`函数上方写下
```c++
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {

    return 0;
}
```


---
### 第五步
#### 讲解
接下来输入一个数`n`。
在`main`函数里面写下
```c++
int n;
cin >> n;
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输入`n`个数并将这些数更新到线段树的节点中。
在`main`函数里面继续写下
```c++
for (int i = 1; i <= n; ++i) {
    int d;
    cin >> d;
    modify(1, 1, n, i, i, d);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来输入查询的个数`q`。
在`main`函数里面继续写下
```c++
int q;
cin >> q;
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;

    return 0;
}
```



---
### 第八步
#### 讲解
然后实现`query(int p, int l, int r, int x, int y)`函数。
根据线段树区间划分的性质，可以通过比较左右端点，找到要查询的区间。
在`main`函数上方写下
```c++
int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}
int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}
int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;

    return 0;
}
```



---
### 第九步
#### 讲解
最后输入`d`、`x`、`y`调用`query`函数查询得到结果。
在`main`函数里面写下
```c++
while (q--) {
    int d, x, y, c;
    cin >> d >> x >> y;
    if (d == 0) {
        cin >> c;
        modify(1, 1, n, x, y, c);
    } else {
        cout << query(1, 1, n, x, y) << endl;
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}
int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;
    while (q--) {
        int d, x, y, c;
        cin >> d >> x >> y;
        if (d == 0) {
            cin >> c;
            modify(1, 1, n, x, y, c);
        } else {
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) {
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void down(int p, int l, int r) {
    if (col[p]) {
        int mid = (l + r) / 2;
        s[p * 2] += col[p] * (mid - l + 1);
        s[p * 2 + 1] += col[p] * (r - mid);
        col[p * 2] += col[p];
        col[p * 2 + 1] += col[p];
        col[p] = 0;
    }
}
void modify(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        s[p] += (r - l + 1) * c;
        col[p] += c;
        return;
    }
    down(p, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) {
        modify(p * 2, l, mid, x, y, c);
    }
    if (y > mid) {
        modify(p * 2 + 1, mid + 1, r, x, y, c);
    }
    up(p);
}
int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return s[p];
    }
    down(p, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid) {
        res += query(p * 2, l, mid, x, y);
    }
    if (y > mid) {
        res += query(p * 2 + 1, mid + 1, r, x, y);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        modify(1, 1, n, i, i, d);
    }
    int q;
    cin >> q;
    while (q--) {
        int d, x, y, c;
        cin >> d >> x >> y;
        if (d == 0) {
            cin >> c;
            modify(1, 1, n, x, y, c);
        } else {
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`segment_tree_interval`了。
