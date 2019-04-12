#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 210000;
char s[MAX_N];
int sa[MAX_N], t[MAX_N], t2[MAX_N], c[MAX_N], n;
void build_sa(int m)
{
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)
            break;
        m = p;
    }
}
int m;
int cmp_suffix(char* patter, int p) {
    return strncmp(patter, s + sa[p], m);
}
int find(char* P) {
    m = strlen(P);
    if (cmp_suffix(P, 0) < 0) return -1;
    if (cmp_suffix(P, n - 1) > 0) return -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = cmp_suffix(P, mid);
        if (!res) {
            return sa[mid];
        }
        if (res < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int Rank[MAX_N], h[MAX_N];
void get_h() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        if (Rank[i]) {
            j = sa[Rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            h[Rank[i]] = k;
        }
    }
}

int main() {
    char ss[MAX_N];
    cin >> s;
    n = strlen(s);
    build_sa(131);
    get_h();
    while (cin >> ss) {
        cout << find(ss) << endl;
    }
    return 0;
}
