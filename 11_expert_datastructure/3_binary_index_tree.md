# binary_index_tree 的使用
- binary_index_tree

### 文件名
binary_index_tree.cpp

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
这一节我们学习树状数组（一维）算法。
树状数组(Binary Indexed Tree(B.I.T), Fenwick Tree)是一个查询和修改复杂度都为log(n)的数据结构。主要用于查询任意两位之间的所有元素之和，但是每次只能修改一个元素的值；经过简单修改可以在log(n)的复杂度下进行范围修改，但是这时只能查询其中一个元素的值(如果加入多个辅助数组则可以实现区间修改与区间查询)。
树状数组和线段树很像，但能用树状数组解决的问题，基本上都能用线段树解决，而线段树能解决的树状数组不一定能解决。相比较而言，树状数组效率要高很多。
我们先定义好要用得数据。在`main`函数上面写下
```c++
const int MAX_N = 10010;
int C[MAX_N];
int n;
```

#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来输入一个数`n`。
在`main`函数里面写下
```c++
cin >> n;
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;

int main() {
    cin >> n;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;

int main() {
    cin >> n;

    return 0;
}
```

---
### 第三步
#### 讲解
然后在实现`lowbit(int x)`函数。
它只保留"从低位向高位数，第一个数字1"作为运算结果。
这里用到了计算机补码的知识，也可以写成x & ((~x) + 1)。
在`main`函数里继续写下
```c++
int lowbit(int x) {
    return x & (-x);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}

int main() {
    cin >> n;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}

int main() {
    cin >> n;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来实现`getsum(int x)`函数。
1、令res = 0，转第二步；
2、假如x <= 0，算法结束，返回res值，否则res = res + C[x]，转第三步；
3、令x = x – lowbit(x)，转第二步。
在`main`函数上方写下
```c++
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}

int main() {
    cin >> n;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}

int main() {
    cin >> n;

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`change(int x, int c)`函数。
1、当x > n时，算法结束，否则转第二步；
2、C[x] = C[x] + c， x = x + lowbit(x)转第一步。
i = i + lowbit(i)这个过程实际上也只是一个把末尾1补为0的过程。
在`main`函数上方写下
```c++
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输入`n`个数并更新到树状数组的区间中。
在`main`函数里面写下
```c++
for (int i = 1; i <= n; ++i) {
    int d;
    cin >> d;
    change(i, d);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        change(i, d);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        change(i, d);
    }

    return 0;
}
```


---
### 第七步
#### 讲解
最后调用`getsum(i)`输出计算的结果。
在`main`函数里面继续写下
```c++
for (int i = 1; i <= n; ++i) {
    cout << getsum(i) << " ";
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        change(i, d);
    }
    for (int i = 1; i <= n; ++i) {
        cout << getsum(i) << " ";
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 10010;
int C[MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += C[x];
    }
    return res;
}
void change(int x, int c) {
    for (; x <= n; x += x & (-x)) {
        C[x] += c;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        change(i, d);
    }
    for (int i = 1; i <= n; ++i) {
        cout << getsum(i) << " ";
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`binary_index_tree`了。
