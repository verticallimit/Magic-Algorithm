# ac 的使用
- ac

### 文件名
ac.cpp

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
这一节我们学习AC自动机算法。
Aho-Corasick automaton，该算法在1975年产生于贝尔实验室，是著名的多模匹配算法。
要学会AC自动机，我们必须知道什么是Trie，也就是字典树。Trie树，又称单词查找树或键树，是一种树形结构，是一种哈希树的变种。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
一个常见的例子就是给出n个单词，再给出一段包含m个字符的文章，让你找出有多少个单词在文章里出现过。
要搞懂AC自动机，先得有模式树（字典树）Trie和KMP模式匹配算法的基础知识。
AC自动机算法分为3步：构造一棵Trie树，构造失败指针和模式匹配过程。
我们先定义好邻接表的结构。在`main`函数上面写下
```c++
const int MAX_N = 10000;
const int MAX_C = 26;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来我们定义一个`AC_Automaton`结构体
在`main`函数上面写下
```c++
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
} ac;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
} ac;

int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
} ac;

int main() {

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现`init()`函数。
在`AC_Automaton`结构体里继续写下
```c++
void init() {
    memset(ch, -1, sizeof(ch));
    memset(fail, 0, sizeof(fail));
    tot = 0;
    memset(cnt, 0, sizeof(cnt));
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
} ac;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
} ac;

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
然后实现`insert(char* str)`函数。
在`AC_Automaton`结构体里继续写下
```c++
void insert(char* str) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        if (ch[p][str[i] - 'a'] == -1) {
            ch[p][str[i] - 'a'] = ++tot;
        }
        p = ch[p][str[i] - 'a'];
    }
    cnt[p]++;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
} ac;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
} ac;

int main() {

    return 0;
}
```


---
### 第五步
#### 讲解
接下来实现`build()`函数。
这是AC自动机算法的前两步：
1、建立模式的Trie。
2、给Trie添加失败路径。
在`AC_Automaton`结构体里继续写下
```c++
void build() {
    int l = 0, r = 0, Q[MAX_N];
    for (int i = 0; i < MAX_C; i++) {
        if (ch[0][i] == -1) {
            ch[0][i] = 0;
        } else {
            Q[r++] = ch[0][i];
        }
    }
    while (l < r) {
        int p = Q[l++];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[p][i] == -1) {
                ch[p][i] = ch[fail[p]][i];
            } else {
                fail[ch[p][i]] = ch[fail[p]][i];
                Q[r++] = ch[p][i];
            }
        }
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
} ac;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
} ac;

int main() {

    return 0;
}
```


---
### 第六步
#### 讲解
接下来实现`count(char* str)`函数。
根据AC自动机，搜索待处理的文本。
在`AC_Automaton`结构体里继续写下
```c++
int count(char* str) {
    int ret = 0, p = 0;
    for (int i = 0; str[i]; ++i) {
        p = ch[p][str[i] - 'a'];
        int tmp = p;
        while (tmp) {
            ret += cnt[tmp];
            cnt[tmp] = 0;
            tmp = fail[tmp];
        }
    }
    return ret;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {

    return 0;
}
```


---
### 第七步
#### 讲解
接下来调用`ac.init()`进行初始化并插入数据。
在`main`函数里面写下
```c++
ac.init();
ac.insert("abcd");
ac.insert("bcd");
ac.insert("cd");
ac.insert("d");
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {
    ac.init();
    ac.insert("abcd");
    ac.insert("bcd");
    ac.insert("cd");
    ac.insert("d");

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {
    ac.init();
    ac.insert("abcd");
    ac.insert("bcd");
    ac.insert("cd");
    ac.insert("d");

    return 0;
}
```


---
### 第八步
#### 讲解
最后调用`ac.build()`创建多模式集合的Trie树。
输出`ac.count("abcd")`统计的结果。
在`main`函数里面写下
```c++
ac.build();
cout << ac.count("abcd") << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {
    ac.init();
    ac.insert("abcd");
    ac.insert("bcd");
    ac.insert("cd");
    ac.insert("d");
    ac.build();
    cout << ac.count("abcd") << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {
    ac.init();
    ac.insert("abcd");
    ac.insert("bcd");
    ac.insert("cd");
    ac.insert("d");
    ac.build();
    cout << ac.count("abcd") << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`AC自动机`了。
