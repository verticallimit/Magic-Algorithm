# trie 的使用
- trie

### 文件名
trie.cpp

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
这一节我们学习字典(trie)树算法。
又称单词查找树，Trie树，是一种树形结构，是一种哈希树的变种。典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。它的优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希树高。
字典树与字典很相似,当你要查一个单词是不是在字典树中,首先看单词的第一个字母是不是在字典的第一层,如果不在,说明字典树里没有该单词,如果在就在该字母的孩子节点里找是不是有单词的第二个字母,没有说明没有该单词,有的话用同样的方法继续查找。字典树不仅可以用来储存字母,也可以储存数字等其它数据。
我们先定义要用的数据。在`main`函数上面写下
```c++
const int maxn = 10010;
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;

int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来定义一个字典树结构体。
在`main`函数上方写下
```c++
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
} trie;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
} trie;

int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
} trie;

int main() {

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现`init()`函数。
在结构体`Trie`里继续写下
```c++
void init() {
    memset(ch[0], 0, sizeof(ch[0]));
    cnt[0] = 0;
    num = 0;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
} trie;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
} trie;

int main() {

    return 0;
}
```


---
### 第四步
#### 讲解
然后实现`newnode()`函数。
在结构体`Trie`里继续写下
```c++
int newnode() {
    ++num;
    memset(ch[num], 0, sizeof(ch[num]));
    cnt[num] = 0;
    return num;
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
} trie;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
} trie;

int main() {

    return 0;
}
```


---
### 第五步
#### 讲解
然后实现`insert(char *s)`函数。
在结构体`Trie`里继续写下
```c++
void insert(char *s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
        if (!ch[u][s[i] - 'a']) {
            ch[u][s[i] - 'a'] = newnode();
        }
        u = ch[u][s[i] - 'a'];
        ++cnt[u];
    }
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
} trie;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
} trie;

int main() {

    return 0;
}
```


---
### 第六步
#### 讲解
然后实现`query(char *s)`函数。
Trie的查找（主要的操作）：
(1) 每次从根结点开始一次搜索；
(2) 取得要查找关键词的第一个字母，并根据该字母选择对应的子树并转到该子树继续进行检索；
(3) 在相应的子树上，取得要查找关键词的第二个字母,并进一步选择对应的子树进行检索。 　　
(4) 迭代过程
(5) 在某个结点处，关键词的所有字母已被取出，则读取附在该结点上的信息，即完成查找。
在结构体`Trie`里继续写下
```c++
int query(char *s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
        if (!ch[u][s[i] - 'a']) {
            return 0;
        }
        u = ch[u][s[i] - 'a'];
    }
    return cnt[u];
}
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {

    return 0;
}
```

---
### 第七步
#### 讲解
接下来初始化字典树。
在`main`函数里面写下
```c++
trie.init();
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();

    return 0;
}
```


---
### 第八步
#### 讲解
接下来往字典树里插入英文单词。
在`main`函数里面继续写下
```c++
trie.insert("china");
trie.insert("chinese");
trie.insert("children");
trie.insert("check");
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();
    trie.insert("china");
    trie.insert("chinese");
    trie.insert("children");
    trie.insert("check");

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();
    trie.insert("china");
    trie.insert("chinese");
    trie.insert("children");
    trie.insert("check");

    return 0;
}
```


---
### 第九步
#### 讲解
最后输出字典树的查询结果。
在`main`函数里面继续写下
```c++
cout << trie.query("ch") << endl;
cout << trie.query("chi") << endl;
cout << trie.query("chin") << endl;
cout << trie.query("china") << endl;
cout << trie.query("beijing") << endl;
```

#### 提示
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();
    trie.insert("china");
    trie.insert("chinese");
    trie.insert("children");
    trie.insert("check");
    cout << trie.query("ch") << endl;
    cout << trie.query("chi") << endl;
    cout << trie.query("chin") << endl;
    cout << trie.query("china") << endl;
    cout << trie.query("beijing") << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();
    trie.insert("china");
    trie.insert("chinese");
    trie.insert("children");
    trie.insert("check");
    cout << trie.query("ch") << endl;
    cout << trie.query("chi") << endl;
    cout << trie.query("chin") << endl;
    cout << trie.query("china") << endl;
    cout << trie.query("beijing") << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`trie树`了。
