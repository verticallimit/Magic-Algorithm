#include <stdio.h>
#include <queue>

using namespace std;
struct point {
    int x, y, step;
    point(int _x, int _y, int _step):
        x(_x), y(_y), step(_step) {}
};

int n, m;
char maze[110][110];
bool vis[110][110];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool in(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < m;
}

int bfs(int sx, int sy) {
    queue<point> q;
    q.push(point(sx, sy, 0));
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
                q.push(point(tx, ty, step + 1));
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
