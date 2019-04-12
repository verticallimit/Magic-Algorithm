#include <iostream>
#include <set>
using namespace std;
int main() {
    set<string> country;
    country.insert("China");
    country.insert("America");
    country.insert("France");
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); ++it) {
        cout << * it << " ";
    }
    cout << endl;
    country.erase("American");
    country.erase("England");
    if (country.count("China")) {
        cout << "China in country." << endl;
    }
    country.clear();
    return 0;
}
