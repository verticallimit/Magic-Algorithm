# prime 的使用
- prime

### 文件名
prime.cpp

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
这一节我们学习如何素数打表，如求100以内的素数有哪些。
素数又称为质数，质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数。
先定义一个布尔类型的标记数组`is_prime`。在`main`函数上方写下
```c++
bool is_prime[100];
```

#### 代码
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
我们要用埃式筛法来快速筛选素数。
算法思路：我们从最小的素数2开始，把2的倍数的数排除，然后把3的倍数的数排除，因为4是2的倍数已经被排除了，所以再把5的倍数的数排除，一直这样把所有的素数的倍数排除，剩下的就只有素数了。
我们先初始化数组，在`main`函数里面写下
```c++
for (int i = 2; i < 100; ++i) {
    is_prime[i] = 1;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }

    return 0;
}
```

---
### 第三步
#### 讲解
然后实现上面的埃式筛法。注意我们只需遍历到sqrt(100)，因为后面是重复的。
根据上面的思路我们可以实现代码如下
```c++
for (int i = 2; i * i < 100; ++i) {
    if (is_prime[i]) {
        for (int j = i * i; j < 100; j +=i) {
            is_prime[j] = 0;
        }
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i < 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j +=i) {
                is_prime[j] = 0;
            }
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i < 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j +=i) {
                is_prime[j] = 0;
            }
        }
    }

    return 0;
}
```


---
### 第四步
#### 讲解
最后输出我们计算出来的100以内的所有素数的值。在`main`里继续写下
```c++
for (int i = 2; i < 100; ++i) {
    if (is_prime[i] == 1) {
        cout << i << " ";
    }
}
cout << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i < 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j +=i) {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 100; ++i) {
        if (is_prime[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i < 100; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j +=i) {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 100; ++i) {
        if (is_prime[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
```



---
### 完成讲解
这一节已经完成了，赶紧运行看看效果。

聪明的你一定学会了怎么素数打表了。
