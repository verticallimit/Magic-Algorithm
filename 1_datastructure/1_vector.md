# vector 的使用
- vector

### 文件名
vector.cpp

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
首先我们引入需要的头文件`vector`，在代码头部写下
```c++
#include <vector>
```

#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们学习如何使用一维的`vector`。

在`main`函数里面通过`vector<int> v`来定义一个储存整数的空的`vector`。当然`vector`可以存任何类型的数据，比如`vector<string> v`等等。在本课中我们用 int 来举例。
```c++
vector<int> v;
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;

    return 0;
}
```

---
### 第三步
#### 讲解
我们把 $1$ 到 $10$ 的平方依次存到`vector`。
在刚才的定义下面写下
```c++
for (int i = 1; i <= 10; ++i) {
    v.push_back(i * i);
}
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }

    return 0;
}
```


---
### 第四步
#### 讲解
然后依次输出我们刚才压入`vector`的值。继续写下
```c++
for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}
cout << endl;
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
```

---
### 第五步
#### 讲解
到这里，里可以点击**运行**看看效果。

接下来我们学习二维的`vector`的使用。二维的`vector`就是一个`vector`里面在套一个`vector`。通过如下的代码定义一个空的二维的`vector`。在刚才的输出代码后面继续写下，**特别注意：里面的`vector<int>`后面有一个空格，这个空格不能到少，因为在没有开启 c++11 的情况下，会被识别成一个`>>`**。
```c++
vector<vector<int> > v2d;
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;

    return 0;
}
```




---
### 第六步
#### 讲解
接下来我们给第一维赋值，第一维是一个一维的`vector`，在定义后面写下：
```c++
for (int i = 0; i < 5; ++i) {
    v2d.push_back(vector<int>());
}
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }

    return 0;
}
```

---
### 第七步
#### 讲解
我们让第 $i$ 行第 $j$ 列的元素的值为 $i*j$。继续写下下面的代码：
```c++
for (int i = 0; i < v2d.size(); ++i) {
    for (int j = 0; j < 5; ++j) {
        v2d[i].push_back(i * j);
    }
}
```



#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            v2d[i].push_back(i * j);
        }
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            v2d[i].push_back(i * j);
        }
    }

    return 0;
}
```



---
### 第八步
#### 讲解
然后我们输出一个 $5$ 行 $5$ 列的矩阵。
```c++
for (int i = 0; i < v2d.size(); ++i) {
    for (int j = 0; j < v2d[i].size(); ++j) {
        cout << v2d[i][j] << " ";
    }
    cout << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            v2d[i].push_back(i * j);
        }
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < v2d[i].size(); ++j) {
            cout << v2d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            v2d[i].push_back(i * j);
        }
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < v2d[i].size(); ++j) {
            cout << v2d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```




---
### 完成讲解
这一节已经完成了，赶紧运行看看效果。

聪明的你一定学会了`vector`怎么用了。
