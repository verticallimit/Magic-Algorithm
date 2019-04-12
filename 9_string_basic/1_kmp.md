# kmp 的使用
- kmp

### 文件名
kmp.cpp

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
这一节我们学习字符串模式匹配（KMP）算法。
KMP算法的思想是：设s为目标串，t为模式串，并设i指针和j指针分别指示目标串和模式串中正待比较的字符，令i和j的初始值均为0。若有si=tj，则i和j分别增1；否则，i不变，j退回到j=next[j]的位置（即模式串右滑），比较si和tj，若相等则指针各增1，否则j再退回到下一个j=next[j]的位置(即模式串继续右滑)，再比较si和tj。依次类推，直到出现下列两种情况之一为止：一种情况是j退回到某个j=next[j]位置时有si=tj，则指针各增1后继续匹配；另一种情况是j退回到j=-1，此时令i、j指针各增1，即从s(i+1)和t0开始继续匹配。
我们先定义`Next`数组。在`main`函数上面写下
```c++
int Next[1110];
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来输入字符串`s`和`T`。
在`main`函数里面写下
```c++
char s[1100], T[1100];
cin >> T >> s;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];

int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];

int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现`get_Next(char *p)`函数。
预处理出`Next`数组是算法的关键。
在`main`函数上面写下
```c++
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来根据前面的思想实现`kmp(char *T, char *s)`函数。
在`main`函数上方写下
```c++
int kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != s[j]) {
            j = Next[j];
        }
        if (s[j] == T[i]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1;
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
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != s[j]) {
            j = Next[j];
        }
        if (s[j] == T[i]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != s[j]) {
            j = Next[j];
        }
        if (s[j] == T[i]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
int main() {
    char s[1100], T[1100];
    cin >> T >> s;

    return 0;
}
```


---
### 第五步
#### 讲解
最后调用`kmp(T, s)`函数输出计算的结果。在`main`函数里面写下
```c++
cout << kmp(T, s) << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != s[j]) {
            j = Next[j];
        }
        if (s[j] == T[i]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
int main() {
    char s[1100], T[1100];
    cin >> T >> s;
    cout << kmp(T, s) << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p) {
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j]) {
            j = Next[j];
        }
        Next[i + 1] = p[i] ==p [j] ? j + 1 : 0;
    }
}

int kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != s[j]) {
            j = Next[j];
        }
        if (s[j] == T[i]) {
            ++j;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
int main() {
    char s[1100], T[1100];
    cin >> T >> s;
    cout << kmp(T, s) << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`kmp算法`了。
