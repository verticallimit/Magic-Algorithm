# euler 的使用
- euler

### 文件名
euler.cpp

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
这一节我们学习欧拉函数。
在数论，对正整数n，欧拉函数是小于n的正整数中与n互质的数的数目（φ(1)=1）
互质是公约数只有1的两个整数，叫做互质整数。
先输入一个整数`n`，我们来求`n`的欧拉函数值。在`main`函数里面写下
```c++
int n;
cin >> n;
```

#### 代码
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    return 0;
}
```

---
### 第二步
#### 讲解
先来看一个欧拉函数的性质
对于一个正整数N的素数幂分解N = P1^q1 * P2^q2 * ... * Pn^qn。
φ(N) = N * (1 - 1/P1) * (1 - 1/P2) * ... * (1 - 1/Pn)
于是我们可以在O(sqrt(n))的时间内求出一个数的欧拉函数值
我们先初始化数组，在`main`函数里面写下
```c++
int res = n;
for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
        res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
        while (n % i == 0) {
            n /= i;
        }
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
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
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    return 0;
}
```

---
### 第三步
#### 讲解
可以发现上面的遍历是经过优化的，只遍历到sqrt(n),但是有可能还剩一个较大的质数因子。
所以还需加上一下的代码
```c++
if (n > 1) {
    res = res / n * (n - 1);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }

    return 0;
}
```


---
### 第四步
#### 讲解
最后输出我们计算出来的`n`的欧拉函数的值。在`main`里继续写下
```c++
cout << res << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }
    cout << res << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据溢出
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }
    cout << res << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
18
```
聪明的你一定学会了如何求一个数的欧拉函数值了吧。
