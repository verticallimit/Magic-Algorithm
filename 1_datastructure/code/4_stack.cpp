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
