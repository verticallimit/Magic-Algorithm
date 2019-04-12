# 2d_binary_index_tree 的使用
- 2d_binary_index_tree

### 文件名
2d_binary_index_tree.cpp

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
这一节我们学习树状数组（二维）算法。
上一节讲了一维树状数组，树状数组可以扩充到二维。
问题：一个由数字构成的大矩阵，能进行两种操作
1) 对矩阵里的某个数加上一个整数（可正可负）。
2) 查询某个子矩阵里所有数字的和,要求对每次查询，输出结果。
一维树状数组很容易扩展到二维，在二维情况下:数组a[][]的树状数组定义为：
C[x][y] = ∑a[i][j], 其中：
x-lowbit(x) + 1 <= i <= x，
y-lowbit(y) + 1 <= j <= y。
我们先定义好要用得数据。在`main`函数上面写下
```c++
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
```

#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
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
const int MAX_N = 810;
int C[MAX_N][MAX_N];
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
const int MAX_N = 810;
int C[MAX_N][MAX_N];
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
```c++
int lowbit(int x) {
    return x & (-x);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
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
const int MAX_N = 810;
int C[MAX_N][MAX_N];
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
接下来实现`change(int i, int j, int delta)`函数。
C[x][y] = ∑a[i][j], 其中：
x-lowbit(x) + 1 <= i <= x，
y-lowbit(y) + 1 <= j <= y。
在`main`函数上方写下
```c++
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
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
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}

int main() {
    cin >> n;

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`getsum(int i, int j)`函数。
在`main`函数上方写下
```c++
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
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
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来输入`n * n`个数并更新到二维树状数组的区间中。
在`main`函数里面写下
```c++
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        int d;
        cin >> d;
        change(i, j, d);
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }

    return 0;
}
```


---
### 第七步
#### 讲解
接下来输入`x`和`y`表示查询的区间。
在`main`函数里面写下
```c++
int x, y;
cin >> x >> y;
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }
    int x, y;
    cin >> x >> y;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }
    int x, y;
    cin >> x >> y;

    return 0;
}
```


---
### 第七步
#### 讲解
最后调用` getsum(x, y)`输出计算的结果。
在`main`函数里面继续写下
```c++
cout << getsum(x, y) << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }
    int x, y;
    cin >> x >> y;
    cout << getsum(x, y) << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
const int MAX_N = 810;
int C[MAX_N][MAX_N];
int n;
int lowbit(int x) {
    return x & (-x);
}
void change(int i, int j, int delta){
    for(int x = i; x <= n; x += lowbit(x)) {
        for(int y = j; y <= n; y += lowbit(y)) {
            C[x][y] += delta;
        }
    }
}
int getsum(int i, int j){
   int res = 0;
   for(int x = i; x; x -= lowbit(x)) {
        for(int y = j; y; y -= lowbit(y)) {
            res += C[x][y];
        }
   }
   return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            change(i, j, d);
        }
    }
    int x, y;
    cin >> x >> y;
    cout << getsum(x, y) << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`2d_binary_index_tree`了。
