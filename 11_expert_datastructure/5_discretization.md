# discretization 的使用
- discretization

### 文件名
discretization.cpp

### 分数
1

---
### 初始化代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {

    return 0;
}
```

---
### 第一步
#### 讲解
这一节我们学习离散化处理。
先举一个例子说明：
给定平面上的n个矩形（坐标为整数，矩形与矩形之间可能有重叠的部分），求其覆盖的总面积。平常的想法就是开一个与二维坐标规模相当的二维Boolean数组模拟矩形的“覆盖”（把矩形所在的位置填上True）。可惜这个想法在这里有些问题，因为这个题目中坐标范围相当大（坐标范围为-10^8到10^8之间的整数）。但我们发现，矩形的数量n<=100远远小于坐标范围。每个矩形会在横纵坐标上各“使用”两个值， 100个矩形的坐标也不过用了-10^8到10^8之间的200个值。也就是说，实际有用的值其实只有这么几个。这些值将作为新的坐标值重新划分整个平面，省去中间的若干坐标值没有影响。我们可以将坐标范围“离散化”到1到200之间的数，于是一个200*200的二维数组就足够了。
实现方法：“排序后处理”对横坐标（或纵坐标）进行一次排序并映射为1到2n的整数，同时记录新坐标的每两个相邻坐标之间在离散化前实际的距离是多少。
我们先定义好要用的数据。在`main`函数上面写下
```c++
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
```

#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {

    return 0;
}
```

---
### 第二步
#### 讲解
接下来输入一个整数`n`,表示总共要输入`n`个数。
在`main`函数里面写下
```c++
cin >> n;
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;

    return 0;
}
```

#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;

    return 0;
}
```

---
### 第三步
#### 讲解
然后输入`n`个数并对应映射到`temp`辅助数组中。
在`main`函数里继续写下
```c++
for (int i = 0; i < n; ++i) {
    cin >> num[i];
    temp[i] = num[i];
}
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }

    return 0;
}
```


---
### 第四步
#### 讲解
接下来进行排序处理。
在`main`函数里面继续写下
```c++
sort(temp, temp + n);
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);

    return 0;
}
```


---
### 第五步
#### 讲解
接下来就是去重操作。
`unique`的作用是删除`temp`里相邻且重复的元素。
在`main`函数里面继续写下
```c++
int m = unique(temp, temp + n) - temp;
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;

    return 0;
}
```


---
### 第六步
#### 讲解
接下来我们将剩下的`m`个不重复的元素重新离散化到`mp`容器中。
在`main`函数里面继续写下
```c++
for (int i = 0; i < m; ++i) {
    mp[temp[i]] = i + 1;
}
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;
    for (int i = 0; i < m; ++i) {
        mp[temp[i]] = i + 1;
    }

    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;
    for (int i = 0; i < m; ++i) {
        mp[temp[i]] = i + 1;
    }

    return 0;
}
```


---
### 第七步
#### 讲解
最后在`main`函数里调用`mp[num[i]]`，输出离散化完成的结果。
在`main`函数里面继续写下
```c++
for (int i = 0; i < n; ++i) {
    cout << mp[num[i]] << " ";
}
```

#### 提示
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;
    for (int i = 0; i < m; ++i) {
        mp[temp[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << mp[num[i]] << " ";
    }
    return 0;
}
```


#### 代码
```c++
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10010;
int num[maxn];
int temp[maxn];
int n;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;
    for (int i = 0; i < m; ++i) {
        mp[temp[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << mp[num[i]] << " ";
    }
    return 0;
}
```



---
### 完成讲解
终于完成了，点击运行，看看效果吧。

聪明的你一定学会了如何使用`discretization`了。
