# set 的使用
- set

### 文件名
set.cpp

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
首先我们引入需要的头文件`set`，在代码头部写下
```c++
#include <set>
```

#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
首先我们学习如何创建一个`set`。

在`main`函数里面通过`set<string> country`来定义一个储存字符串的空的`set`。当然`set`可以存任何类型的数据，比如`set<int> s`等等。在本课中我们用 string 来举例。
```c++
set<string> country;
```

#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;

    return 0;
}
```

---
### 第三步
#### 讲解
我们把`China` `America` `France`依次插入到`set`。
在刚才的定义下面写下
```c++
country.insert("China");
country.insert("America");
country.insert("France");
```

#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");

    return 0;
}
```


---
### 第四步
#### 讲解
然后依次输出我们刚才插入`set`的字符串。继续写下
```c++
set<string>::iterator it;
for (it = country.begin(); it != country.end(); ++it) {
    cout << * it  << " ";
}
cout << endl;
```

#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;

    return 0;
}
```

---
### 第五步
#### 讲解
到这里，里可以点击**运行**看看效果。
可以发现我们刚才插入的字符串按照字典序排列好了。

接下来我们学习`set`的删除操作。
```c++
country.erase("American");
country.erase("England");
```

#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");

    return 0;
}
```




---
### 第六步
#### 讲解
接下来我们统计`set`中`China`字符串的个数
```c++
if (country.count("China")) {
    cout << "China in country." << endl;
}
```

#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");
    if (country.count("China")) {
        cout << "China in country." << endl;
    }

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");
    if (country.count("China")) {
        cout << "China in country." << endl;
    }

    return 0;
}
```

---
### 第七步
#### 讲解
最后我们将使用完成的`set`清空。继续写下下面的代码：
```c++
country.clear();
```



#### 提示
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");
    if (country.count("China")) {
        cout << "China in country." << endl;
    }
    country.clear();

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it  << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");
    if (country.count("China")) {
        cout << "China in country." << endl;
    }
    country.clear();

    return 0;
}
```



---
### 完成讲解
这一节已经完成了，赶紧运行看看效果。

聪明的你一定学会了`set`怎么用了。
