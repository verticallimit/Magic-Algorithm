#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<vector<int> > v2d;
    for (int i = 0; i < 5; ++i) {
        v2d.push_back(vector<int>());
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            v2d[i].push_back(i * j);
        }
    }
    for (int i = 0; i < v2d.size(); ++i) {
        for (int j = 0; j < v2d[i].size(); ++j) {
            cout << v2d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
