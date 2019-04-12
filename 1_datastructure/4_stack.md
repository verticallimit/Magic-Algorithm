# stack 的使用
- stack

### 文件名
stack.cpp

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
首先我们引入需要的头文件`stack`，在代码头部写下
```c++
#include <stack>
```

#### 代码
```c++
#include <iostream>
#include <stack>
using namespace std;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们学习如何使用`stack`。

在`main`函数上方通过`stack<int> S`来定义一个全局栈来储存整数的空的`stack`。当然`stack`可以存任何类型的数据，比如`stack<string> S`等等。在本课中我们用 int 来举例。
```c++
stack<int> S;
```

#### 提示
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {

    return 0;
}
```

---
### 第三步
#### 讲解
我们把`1` `10` `7`三个数依次存到`stack`。
在`main`函数里写下
```c++
S.push(1);
S.push(10);
S.push(7);
```

#### 提示
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);

    return 0;
}
```


---
### 第四步
#### 讲解
然后我们判断一下`stack`的是否为空。继续写下
```c++
while (!S.empty()) {

}
```

#### 提示
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);
    while (!S.empty()) {

    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);
    while (!S.empty()) {

    }

    return 0;
}
```

---
### 第五步
#### 讲解
如果`stack`不为空，我们将`stack`里的数依次取出来，在`while`里继续写下
```c++
cout << S.top() << endl;
S.pop();
```

#### 提示
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);
    while (!S.empty()) {
      cout << S.top() << endl;
      S.pop();
    }
    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <stack>
using namespace std;
stack<int> S;
int main() {
    S.push(1);
    S.push(10);
    S.push(7);
    while (!S.empty()) {
      cout << S.top() << endl;
      S.pop();
    }
    return 0;
}
```




---
### 完成讲解
这一节已经完成了，赶紧运行看看效果，可以发现`stack`有先进后出的特性。

聪明的你一定学会了`stack`怎么用了。
