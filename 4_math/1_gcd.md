# gcd 的使用
- gcd

### 文件名
gcd.cpp

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
这一节我们学习如何求两个整数的最大公因数。
最大公因数，也称最大公约数、最大公因子，指两个或多个整数共有约数中最大的一个。
先定义两个整数`n`和`m`并从键盘输入。在`main`函数里写下
```c++
int n, m;
cin >> n >> m;
```

#### 代码
```c++
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们定义一个`gcd`函数，这个函数用来用来求传入的两个参数的最大公约数。

在`main`函数上方写下
```c++
int gcd(int a, int b) {

}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {

}
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {

}
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们要实现`gcd`的具体过程。
我们要用到辗转相除的方法来计算两个数的最大公约数。
过程如下：
1、a % b得余数c
2、若c = 0,则b即为两数的最大公约数
3、若c != 0,则a = b, b = c,再回去执行过程1
根据上面的思路我们可以实现代码如下
```c++
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int n, m;
    cin >> n >> m;

    return 0;
}
```


---
### 第四步
#### 讲解
最后输出所求的`gcd`的值。在`main`里继续写下
```c++
cout << gcd(n, m) << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << endl;
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
8 12
```
