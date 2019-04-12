# queue 的使用
- queue

### 文件名
queue.cpp

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
首先我们引入需要的头文件`queue`，在代码头部写下
```c++
#include <queue>
```

#### 代码
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们学习如何使用`queue`。

在`main`函数里面通过`queue<int> q`来定义一个储存整数的空的`queue`。当然`queue`可以存任何类型的数据，比如`queue<string> q`等等。在本课中我们用 int 来举例。
```c++
queue<int> q;
```

#### 提示
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;

    return 0;
}
```

---
### 第三步
#### 讲解
我们把`1` `2` `3`三个数依次存到`queue`。
在`main`函数里写下
```c++
q.push(1);
q.push(2);
q.push(3);
```

#### 提示
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    return 0;
}
```


---
### 第四步
#### 讲解
然后我们判断一下`queue`的是否为空。继续写下
```c++
while (!q.empty()) {

}
```

#### 提示
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {

    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {

    }

    return 0;
}
```

---
### 第五步
#### 讲解
如果`queue`不为空，我们将`queue`里的数依次取出来，在`while`里继续写下
```c++
cout << q.front() << endl;
q.pop();
```

#### 提示
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
```



---
### 完成讲解
这一节已经完成了，赶紧运行看看效果，可以发现`queue`有先进先出的特性。

聪明的你一定学会了`queue`怎么用了。
