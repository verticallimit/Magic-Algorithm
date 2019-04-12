#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() {
    map<string, int> dict;
    dict["Tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    if (dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"];
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << " is in class " << it->second << endl;
    }
    dict.clear();
    return 0;
}
