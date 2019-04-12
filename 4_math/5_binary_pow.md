# binary_pow 的使用
- binary_pow

### 文件名
binary_pow.cpp

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
这一节我们学习`binary_pow`(二分快速幂)算法。
我们要求a ^ b % mod的值，可以发现当b非常大的时候，我们的需要将a乘以b次，O(b)的时间复杂度是让人难以接受的。
思考一下：
对于任意一个正整数b是否可以用1,2,4,8,16,32,....,2^n这样的数来组成。
比如7 = 4 + 2 + 1
19 = 16 + 2 + 1
聪明的你是否发现了其中的规律。
先输入`a`和`b`和`mod`三个整数。在`main`函数里面写下
```c++
int a, b, mod;
cin >> a >> b >> mod;
```

#### 代码
```c++
#include <iostream>
using namespace std;
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    return 0;
}
```

---
### 第二步
#### 讲解
根据刚才我们发现的规律，任何一个`b`都可以由2^i次幂的数构成，而且这些数不会有重复的。
于是我们可以用二分的思想来快速将`b`的值分解。
我们先将`Pow_mod`函数框架写好。在`main`函数上面写下
```c++
int Pow_mod(int a, int b, int mod){

}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){

}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){

}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    return 0;
}
```

---
### 第三步
#### 讲解
上面我们可以二分的方法快速将`b`分解成2^i次幂组合成的数。
例如a^7 = a^4 * a^2 * a^1
a^19 = a^16 * a^2 * a^1
我们将`b`转化为二进制之后可以发现7是111,19是10011。
且a^2 = a^1 * a^1
a^4 = a^2 * a^2
于是我们要快速计算一个数a^b，只需要看b的二进制位是0还是1。
根据这个思路我们可以实现代码如下
```c++
int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    return 0;
}
```


---
### 第四步
#### 讲解
最后输出我们所求的结果。在`main`里继续写下
```c++
cout << Pow_mod(a, b, mod) << endl;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;
    cout << Pow_mod(a, b, mod) << endl;
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int Pow_mod(int a, int b, int mod){
    int res = 1, temp = a;
    for (; b; b /= 2) {
        if (b & 1) {
            res = res * temp % mod;
        }
        temp = temp * temp % mod;
    }
    return res;
}
int main() {
    int a, b, mod;
    cin >> a >> b >> mod;
    cout << Pow_mod(a, b, mod) << endl;
    return 0;
}
```

---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
100 100 999
```
