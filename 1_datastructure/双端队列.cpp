#include<algorithm>
#include<deque>
#include<iostream>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.pop_back();
    dq.pop_front();
    deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
