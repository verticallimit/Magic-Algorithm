// 思路是，先讲普通的并查集，然后扩展都带权并查集
// 题目背景是 https://www.jisuanke.com/course/720/37707, 带权并查集部分。


#include <iostream>
using namespace std;
int father[110], n;
int dist[110], size[110];

void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i, dist[i] = 0, size[i] = 1;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    }
    int y = father[x];
    father[x] = get(y);
    dist[x] += dist[y];
    return father[x];
}
void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        father[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}
int main() {
    n = 10;
    init();
    merge(1, 2);
    merge(10, 7);
    merge(3, 4);
    merge(3, 7);
    get(1); // 一定要先 get，可能没有直接连接根节点
    cout << dist[1] + 1 << endl;
    get(3);
    cout << dist[3] + 1 << endl;
    return 0;
}
