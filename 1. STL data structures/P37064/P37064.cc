#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<string> ms;
    string w;
    cin >> w;

    multiset<string>::iterator median_it;
    while (w != "END") {
        if (ms.empty()) median_it = ms.insert(w);
        else {
            ms.insert(w);
            if (ms.size() % 2 == 0 and w < *median_it) --median_it;
            else if (ms.size() % 2 == 1 and w > *median_it) ++median_it;
        }
        cout << *median_it << endl;
        cin >> w;
    }
}