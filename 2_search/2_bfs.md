# bfs 模板
- bfs

### 文件名
bfs.cpp

### 分数
1


---
### 初始化代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char maze[110][110];

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第一步
#### 讲解
通过本节课，我们来用 bfs 算法来解决一个实际问题——迷宫问题。

迷宫问题是在一个方格地图上，求从起点走到终点的最短路。但是迷宫中障碍，有些方格不能走。

我们已经写好了输入，并且找到了起点，现在我们先在`main`函数上面写下`bfs`函数的框架，传入起点。

```c++
int bfs(int sx, int sy) {

}
```

#### 提示
```c++
int bfs(int sx, int sy) {

}

int main() {
    .....
}
```

#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char maze[110][110];


int bfs(int sx, int sy) {

}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```


---
### 第二步
#### 讲解
下面我们定义一个结构体 Point 来存状态信息。一个状态包含点的坐标 $x,y$ 和当前已经走的步数 $step$。同时我们还需要标记某个点是否走过，那么需要另外开一个标记数组 $vis$。在`bfs`函数之前，`maze`定义之后写下。

```c++
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
```
其中 Point 里面有一个构造函数，用来快速构造一个 Point 结构体。



#### 提示
```c++
...
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
int bfs(int sx, int sy) {

}
...
```


#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
int bfs(int sx, int sy) {

}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第三步
#### 讲解
我们知道 bfs 需要用一个队列来维护，下面我们定义一个用来存状态的队列，并且将初始状态压入队列，一并标记初始状态已经访问。在 bfs 函数里面写下。（注释可以不用写）
```c++
queue<Point> q;
q.push(Point(sx, sy, 0)); // 初始的时候走了 0 步
vis[sx][sy] = 1; // 标记起点已经访问了
```

#### 提示
```c++
...
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
}
...
```


#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;

}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```


---
### 第四步
#### 讲解
当队列没有空的时候，我们取出队首元素来扩展其他的状态。在 bfs 函数里面写下
```c++
while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int step = q.front().step;
    q.pop();
}
```

#### 提示
```c++
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    int x = q.front().x;
    int y = q.front().y;
    int step = q.front().step;
    q.pop();
}
```

#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
    }
}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第五步
#### 讲解
接下来我们要对四个方向进行搜索，我们通过定义一个方向向量来控制搜索方向。常量的定义一般写在代码头部，在`using namespace std;`下面写下
```c++
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
```
然后在 bfs 函数的`q.pop()`下面继续写下搜索四个方向的代码
```c++
for (int i = 0; i < 4; ++i) {
    int tx = x + dir[i][0];
    int ty = y + dir[i][1];
}
```

#### 提示
```c++
...
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
...
...
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
        }
    }
}
```

#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
        }
    }
}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第六步
#### 讲解
对于搜索到的点 $(tx, ty)$，我们首先需要判断这个点是不是在地图范围内，在 bfs 函数上方，结构体定义下方新加一个函数
```c++
bool in(int x, int y) {
    // 判断点 (x,y) 是否在地图范围内
    return 0 <= x && x < n && 0 <= y && y < m;
}
```

#### 提示
```c++
...
bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
int bfs(int sx, int sy) {
...
```

#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
        }
    }
}

int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第七步
#### 讲解
对于在地图内不是障碍的点，如果没有访问，标记这个点访问并且压入队列。如果搜到了终点，可以直接返回了。继续写下
```c++
if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
    if (maze[tx][ty] == 'T') {
        return step + 1;
    }
    q.push(Point(tx, ty, step + 1));
    vis[tx][ty] = 1;
}
```
注意，`in(tx, ty)`必须在最前面，防止后面访问`maze`和`vis`数组出现越界。

这样我们的 bfs 函数就完成了。最后有一个小地方，如果没有搜索到终点，我们需要标识没有可行的路径。在 bfs 函数最后面写下`return -1`，这样在没有搜到终点的情况下就返回了`-1`了。


#### 提示
```c++
...
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
                if (maze[tx][ty] == 'T') {
                    return step + 1;
                }
                q.push(Point(tx, ty, step + 1));
                vis[tx][ty] = 1;
            }
        }
    }
    return -1;
}
...

```
#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
                if (maze[tx][ty] == 'T') {
                    return step + 1;
                }
                q.push(Point(tx, ty, step + 1));
                vis[tx][ty] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }

    return 0;
}
```

---
### 第七步
#### 讲解
最后，我们在`main`函数中调用`bfs`函数就可以啦。
```c++
printf("%d\n", bfs(sx, sy));
```

#### 提示
```c++
...
int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    printf("%d\n", bfs(sx, sy));
    return 0;
}
```

#### 代码
```c++
#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m;
char maze[110][110];
bool vis[110][110];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};
bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
int bfs(int sx, int sy) {
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
                if (maze[tx][ty] == 'T') {
                    return step + 1;
                }
                q.push(Point(tx, ty, step + 1));
                vis[tx][ty] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int sx, sy;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    printf("%d\n", bfs(sx, sy));
    return 0;
}
```

---
### 完成讲解
终于完成了，点击运行，输入下面的迷宫看看效果吧。
```
5 4
T...
.##.
##..
...#
##.S
```
