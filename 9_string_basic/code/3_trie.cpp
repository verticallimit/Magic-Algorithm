// 查新前缀单词数
#include <iostream>
#include <string.h>

using namespace std;
const int maxn = 10010;
struct Trie {
    int ch[maxn][26];
    int cnt[maxn];
    int num;
    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        cnt[0] = 0;
        num = 0;
    }
    int newnode() {
        ++num;
        memset(ch[num], 0, sizeof(ch[num]));
        cnt[num] = 0;
        return num;
    }
    void insert(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                ch[u][s[i] - 'a'] = newnode();
            }
            u = ch[u][s[i] - 'a'];
            ++cnt[u];
        }
    }
    int query(char *s) {
        int u = 0;
        for (int i = 0; s[i]; ++i) {
            if (!ch[u][s[i] - 'a']) {
                return 0;
            }
            u = ch[u][s[i] - 'a'];
        }
        return cnt[u];
    }
} trie;

int main() {
    trie.init();
    trie.insert("china");
    trie.insert("chinese");
    trie.insert("children");
    trie.insert("check");
    cout << trie.query("ch") << endl;
    cout << trie.query("chi") << endl;
    cout << trie.query("chin") << endl;
    cout << trie.query("china") << endl;
    cout << trie.query("beijing") << endl;
    return 0;
}
