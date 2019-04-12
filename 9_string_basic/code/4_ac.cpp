#include <iostream>
using namespace std;

const int MAX_N = 10000;
const int MAX_C = 26;
struct AC_Automaton {
    int ch[MAX_N][MAX_C], fail[MAX_N], cnt[MAX_N];
    int tot;
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(fail, 0, sizeof(fail));
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char* str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }
    void build() {
        int l = 0, r = 0, Q[MAX_N];
        for (int i = 0; i < MAX_C; i++) {
            if (ch[0][i] == -1) {
                ch[0][i] = 0;
            } else {
                Q[r++] = ch[0][i];
            }
        }
        while (l < r) {
            int p = Q[l++];
            for (int i = 0; i < MAX_C; i++) {
                if (ch[p][i] == -1) {
                    ch[p][i] = ch[fail[p]][i];
                } else {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    Q[r++] = ch[p][i];
                }
            }
        }
    }
    int count(char* str) {
        int ret = 0, p = 0;
        for (int i = 0; str[i]; ++i) {
            p = ch[p][str[i] - 'a'];
            int tmp = p;
            while (tmp) {
                ret += cnt[tmp];
                cnt[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
} ac;

int main() {
    ac.init();
    ac.insert("abcd");
    ac.insert("bcd");
    ac.insert("cd");
    ac.insert("d");
    ac.build();
    cout << ac.count("abcd") << endl;
    return 0;
}

