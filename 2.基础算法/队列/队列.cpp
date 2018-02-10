#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Queue {
    /* 数组实现 */
    void Queue_Array() {
        int q[1005] = {0};
        int head = 0;
        int tail = head;
        q[tail++] = 1;
        q[tail++] = 2;
        q[tail++] = 3;
        while (head < tail) {
            printf("%d\n", q[head]);
            head++;
        }
    }

    /* STL实现 */
    void Queue_STL() {
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        while (!q.empty()) {
            printf("%d\n", q.front());
            q.pop();
        }
    }
}Q;

int main() {
    Q.Queue_Array();
    Q.Queue_STL();
    return 0;
}
