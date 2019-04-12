# exkmp 的使用
- exkmp

### 文件名
exkmp.cpp

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
这一节我们学习扩展KMP（exkmp）算法。
扩展kmp是对KMP算法的扩展，它解决如下问题：
定义母串S，和子串T，设S的长度为n，T的长度为m，求T与S的每一个后缀的最长公共前缀，也就是说，设extend数组,extend[i]表示T与S[i,n-1]的最长公共前缀，要求出所有extend[i](0<=i<n)。
注意到，如果有一个位置extend[i]=m,则表示T在S中出现，而且是在位置i出现，这就是标准的KMP问题，所以说拓展kmp是对KMP算法的扩展，所以一般将它称为扩展KMP算法。
我们先定义`Next`和`extend`数组。在`main`函数上面写下
```c++
const int maxn=1100;
int Next[maxn], extend[maxn];
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];

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
char s[maxn], T[maxn];
cin >> T >> s;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现`get_Next(char *s)`函数。
预处理出`Next`数组是算法的关键。
在`main`函数上方写下
```c++
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来根据前面的思想实现`ex_kmp(char *T, char *s)`函数，和kmp一样分情况讨论。
在`main`函数上方写下
```c++
void ex_kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    int i, j, k;
    for(j = 0; j < n && j < m && T[j] == s[j]; ++j);
    extend[0] = j;
    k = 0;
    for (i = 1; i < n; ++i) {
        int len = k + extend[k], L = Next[i - k];
        if(L < len-i) {
            extend[i] = L;
        } else {
            for (j = max(0, len - i); j < m && i + j < n && s[j] == T[i + j]; ++j);
            extend[i] = j;
            k = i;
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}
void ex_kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    int i, j, k;
    for(j = 0; j < n && j < m && T[j] == s[j]; ++j);
    extend[0] = j;
    k = 0;
    for (i = 1; i < n; ++i) {
        int len = k + extend[k], L = Next[i - k];
        if(L < len-i) {
            extend[i] = L;
        } else {
            for (j = max(0, len - i); j < m && i + j < n && s[j] == T[i + j]; ++j);
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}
void ex_kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    int i, j, k;
    for(j = 0; j < n && j < m && T[j] == s[j]; ++j);
    extend[0] = j;
    k = 0;
    for (i = 1; i < n; ++i) {
        int len = k + extend[k], L = Next[i - k];
        if(L < len-i) {
            extend[i] = L;
        } else {
            for (j = max(0, len - i); j < m && i + j < n && s[j] == T[i + j]; ++j);
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;

    return 0;
}
```


---
### 第五步
#### 讲解
最后输出所有的`extend[i]`即最长公共前缀。在`main`函数里面写下
```c++
for (int i = 0; i < strlen(T); ++i) {
    cout << extend[i] << " ";
}
cout << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}
void ex_kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    int i, j, k;
    for(j = 0; j < n && j < m && T[j] == s[j]; ++j);
    extend[0] = j;
    k = 0;
    for (i = 1; i < n; ++i) {
        int len = k + extend[k], L = Next[i - k];
        if(L < len-i) {
            extend[i] = L;
        } else {
            for (j = max(0, len - i); j < m && i + j < n && s[j] == T[i + j]; ++j);
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;
    for (int i = 0; i < strlen(T); ++i) {
        cout << extend[i] << " ";
    }
    cout << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1100;
int Next[maxn], extend[maxn];
void get_Next(char *s) {
    int n = strlen(s);
    int i, j, k;
    for(j = 0; 1 + j < n && s[j] == s[1 + j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < n; ++i) {
        int len = k + Next[k], L = Next[i - k];
        if (L < len - i) {
            Next[i] = L;
        } else {
            for (j = max(0, len - i); i + j < n && s[j] == s[i + j]; ++j);
            Next[i] = j;
            k = i;
        }
    }
    Next[0] = n;
}
void ex_kmp(char *T, char *s) {
    int n = strlen(T), m = strlen(s);
    int i, j, k;
    for(j = 0; j < n && j < m && T[j] == s[j]; ++j);
    extend[0] = j;
    k = 0;
    for (i = 1; i < n; ++i) {
        int len = k + extend[k], L = Next[i - k];
        if(L < len-i) {
            extend[i] = L;
        } else {
            for (j = max(0, len - i); j < m && i + j < n && s[j] == T[i + j]; ++j);
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    char s[maxn], T[maxn];
    cin >> T >> s;
    for (int i = 0; i < strlen(T); ++i) {
        cout << extend[i] << " ";
    }
    cout << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`exkmp算法`了。
