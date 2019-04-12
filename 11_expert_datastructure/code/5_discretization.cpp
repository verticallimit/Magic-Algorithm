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
