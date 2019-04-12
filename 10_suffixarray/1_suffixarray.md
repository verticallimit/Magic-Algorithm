# suffixarray 的使用
- suffixarray

### 文件名
suffixarray.cpp

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
这一节我们学习后缀数组`suffixarray`算法。
后缀数组 sa 是一个一维数组，它保存 1..n 的某个排列 sa[1] ，sa[2] ，...， sa[n] ，并且保证suffix(sa[i]) < Suffix(sa[i+1]) ， 1 ≤ i<n 。也就是将 S 的 n 个后缀从小到大进行排序之后把排好序的后缀的开头位置顺次放入 sa 中。
我们先定义好要用的数据。在`main`函数上面写下
```c++
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来我们输入一个字符串`s`并计算它的长度。
在`main`函数里面写下
```c++
char ss[MAX_N];
cin >> s;
n = strlen(s);
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```

---
### 第三步
#### 讲解
接下来实现`build_sa(int m)`函数。
Suffix[i]：字符串下标为i ~ Len的连续子串(即后缀)
Rank[i]:名次数组 Rank[i] 保存的是 以下标 i 开头的后缀在所有后缀中从小到大排列的 “ 名次 ” 。
sa[i] : 满足Suffix[sa[1]] < Suffix[sa[2]]...< Suffix[sa[Len]],即排名为i的后缀为Suffix[sa[i]] (与Rank是互逆运算)
倍增算法的主要思想 ：对于一个后缀Suffix[i],如果想直接得到Rank比较困难，但是我们可以对每个字符开始的长度为2k的字符串求出排名，k从0开始每次递增1(每递增1就成为一轮)，当2k大于Len时，所得到的序列就是Rank，而sa也就知道了。基数排序是实现的关键部分。
在`main`函数上方写下
```c++
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


---
### 第四步
#### 讲解
接下来实现`cmp_suffix(char* patter, int p)`函数。
在`main`函数上方写下
```c++
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`find(char* P)`函数。
因为字符串已经排好序了，使用二分查找可以加快查找的效率。
在`main`函数上方写下
```c++
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


---
### 第六步
#### 讲解
接下来实现`get_h()`函数求h数组。h[i] 表示sa[i]和sa[i-1]的最长前缀
在`main`函数上面写下
```c++
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);

    return 0;
}
```


---
### 第七步
#### 讲解
最后在`main`函数里调用`build_sa(131)`和`get_h()`预处理出`sa数组`和`h数组`。
在`main`函数里面写下
```c++
build_sa(131);
get_h();
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);
    build_sa(131);
    get_h();

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);
    build_sa(131);
    get_h();

    return 0;
}
```


---
### 第八步
#### 讲解
最后调用`find(ss)`查找字符串的排名。
在`main`函数里面写下
```c++
while (cin >> ss) {
    cout << find(ss) << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);
    build_sa(131);
    get_h();
    while (cin >> ss) {
        cout << find(ss) << endl;
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);
    build_sa(131);
    get_h();
    while (cin >> ss) {
        cout << find(ss) << endl;
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`suffixarray`了。
