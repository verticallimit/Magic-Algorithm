# exgcd 的使用
- exgcd

### 文件名
exgcd.cpp

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
这一节我们学习`exgcd`(扩展GCD)算法。
首先来看一个结论：对于不完全为`0`的非负整数`a`，`b`，`gcd（a，b）`表示 `a`，`b` 的最大公约数，必然存在整
数对 `x`，`y` ，使得 `gcd（a，b）= ax + by`。
`exgcd`就是在已知`a`,`b`的情况下求解`x`和`y`。
先输入`a`和`b`两个整数。在`main`函数里面写下
```c++
int a, b, x, y;
cin >> a >> b;
```

#### 代码
```c++
#include <iostream>
using namespace std;
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```

---
### 第二步
#### 讲解
然后将`exgcd`的函数框架写好。在`main`函数上面写下
```c++
int exgcd(int a, int b, int &x, int &y) {

}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {

}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {

}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```

---
### 第三步
#### 讲解
接下来我们来简单整理一下思路。
1、当 b = 0，gcd（a，b）= a，此时 x = 1，y = 0。
2、对于方程ax + by = gcd(a, b)；我们设解为x1,  y1
我们令a = b, b = a % b;
得到方程bx + a % by = gcd(b， a % b);
由欧几里得算法可以得到gcd(a, b) = gcd(b, a % b);
代入可得：bx + a % b y = gcd(a, b)
设此方程解为x2, y2；
将模运算转换可得： a % b = a - (a / b) * b;
代入方程化解得：
ay2 + b(x2 - (a / b) y2) = gcd(a, b);
与ax1 + by1 = gcd(a, b) 联立，我们很容易得：
x1 = y2, y1 = x2 - (a / b)y2;
然后就可以递归求解。根据这个思路我们可以实现第一步代码如下
```c++
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```


---
### 第四步
#### 讲解
接着实现第二步的代码。在`exgcd`里继续写下
```c++
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;

    return 0;
}
```



---
### 第五步
#### 讲解
然后我们调用已经写好的`exgcd`函数。在`main`里继续写下
```c++
int d = exgcd(a, b, x, y);
```

#### 提示
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, x, y);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, x, y);

    return 0;
}
```



---
### 第六步
#### 讲解
最后输出结果。在`main`里继续写下
```c++
cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
    return 0;
}
```


---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
7 9
```
提示：当gcd(a, b) != 1时，我们很容易发现方程是无解的。
