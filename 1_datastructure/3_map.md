# map 的使用
- map

### 文件名
map.cpp

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
首先我们引入需要的头文件`map`，在代码头部写下
```c++
#include <map>
#include <string>
```

#### 代码
```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们学习如何创建一个`map`。

在`main`函数里面通过`map<string, int> dict`来定义一个`key:value`映射关系的空的`map`。当然`map`可以存任何类型的数据，比如`map<int, int> m`等等。在本课中我们用`string:int`来举例。
```c++
map<string, int> dict;
```

#### 提示
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;

    return 0;
}
```

---
### 第三步
#### 讲解
我们把`Tom` `Jone` `Mary`依次插入到`map`并一一对应的赋值。
在刚才的定义下面写下
```c++
dict["Tom"] = 1;
dict["Jone"] = 2;
dict["Mary"] = 1;
```

#### 提示
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;

    return 0;
}
```


---
### 第四步
#### 讲解
接下来我们查看`map`中`Mary`对应的value值，先判断一下`map`中是否有`Mary`。继续写下
```c++
if (dict.count("Mary")) {
    cout << "Mary is in class " << dict["Mary"];
}
```

#### 提示
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }

    return 0;
}
```

---
### 第五步
#### 讲解
到这里，里可以点击**运行**看看效果。

接下来我们学习`map`的遍历操作。
```c++
for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
    cout << it->first << " is in class " << it->second << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << " is in class " << it->second << endl;
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << " is in class " << it->second << endl;
    }

    return 0;
}
```




---
### 第六步
#### 讲解
到这里，里可以点击**运行**看看效果。
可以发现`map`里的key字符串按照字典序排列好了。

最后我们再清空`map`
```c++
dict.clear();
```

#### 提示
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << " is in class " << it->second << endl;
    }
    dict.clear();
    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << " is in class " << it->second << endl;
    }
    dict.clear();
    return 0;
}
```


---
### 完成讲解
这一节已经完成了，赶紧运行看看效果。

聪明的你一定学会了`map`怎么用了。
