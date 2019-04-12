# matrix_pow 的使用
- matrix_pow

### 文件名
matrix_pow.cpp

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
这一节我们学习`matrix_pow`(矩阵快速幂)算法。
提示：矩阵快速幂和上一节讲的二分快速幂思路是一样的。
我们要求矩阵A ^ y % mod的值，可以发现当y非常大的时候，我们的需要将A乘以y次，O(y)的时间复杂度是让人难以接受的。
思考一下：
对于任意一个正整数y是否可以用1,2,4,8,16,32,....,2^n这样的数来组成。
比如7 = 4 + 2 + 1
19 = 16 + 2 + 1
聪明的你是否发现了其中的规律。
先用结构体类型来定义矩阵`A`。在`main`函数上面写下
```c++
int n;
struct matrix {
   int a[100][100];
};
```

#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
根据刚才我们发现的规律，任何一个`y`都可以由2^i次幂的数构成，而且这些数不会有重复的。
于是我们可以用二分的思想来快速将`b`的值分解。
我们先输入矩阵`A`的值。在`main`函数里面写下
```c++
matrix A;
n = 2;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cin >> A.a[i][j];
    }
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }

    return 0;
}
```

---
### 第三步
#### 讲解
接下来输入`y`和`mod`。在`main`函数里继续写下
```c++
int y, mod;
cin >> y >> mod;
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来初始化一个单位矩阵`E`，单位矩阵主对角线上是1，其他位置是0。在`main`函数上方写下
```c++
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


---
### 第五步
#### 讲解
然后实现矩阵乘法`matrix_mul`函数。在`unit`函数上方写下
```c++
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


---
### 第六步
#### 讲解
上面我们可以二分的方法快速将`y`分解成2^i次幂组合成的数。
例如A^7 = A^4 * A^2 * A^1
A^19 = A^16 * A^2 * A^1
我们将`y`转化为二进制之后可以发现7是111,19是10011。
且A^2 = A^1 * A^1
A^4 = A^2 * A^2
于是我们要快速计算一个A^y，只需要看y的二进制位是0还是1。
根据这个思路我们可以实现代码如下。
在`main`函数上方写下
```c++
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}
int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;

    return 0;
}
```


---
### 第七步
#### 讲解
调用`matrix_pow`函数，最后输出我们所求的矩阵A的结果。在`main`里继续写下
```c++
matrix res = matrix_pow(A, y, mod);
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cout << res.a[i][j] << " ";
    }
    cout << endl;
}
```

#### 提示
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}

int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;
    matrix res = matrix_pow(A, y, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
using namespace std;
int n;
struct matrix {
   int a[100][100];
};
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int y, int mod) {
    matrix res = unit(), temp = A;
    for (; y; y /= 2) {
        if (y & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}

int main() {
    matrix A;
    n = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.a[i][j];
        }
    }
    int y, mod;
    cin >> y >> mod;
    matrix res = matrix_pow(A, y, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---
### 完成讲解
终于完成了，点击运行，输入下面的数据看看效果吧。
```
1 2
3 4
100 999
```
