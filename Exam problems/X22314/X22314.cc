#include <iostream>
#include <map>
using namespace std;

#define LAST_NIF_NUM 7

int main() {
    map<string, int> M;
    char c;
    while (cin >> c) {
        if (c == 'N') {
            cout << "number: " << M.size() << endl;
        }
        else if (c == 'D') {
            string nif;
            int money;
            cin >> nif >> money;
            
            auto it = M.find(nif);
            // if has NOT made donation before
            if (it == M.end()) M.insert({nif, money});
            else M[nif] += money;
        }
        else if (c == 'Q') {
            string nif;
            cin >> nif;
            auto it = M.find(nif);
            // if has NOT made donation before
            if (it == M.end()) cout << "-1" << endl;
            else cout << M[nif] << endl;
        }
        else if (c == 'P') {
            bool first = true;
            for (auto it : M) {
                int num = int(it.first[LAST_NIF_NUM]);
                if (num % 2 == 0) {
                    if (first) first = false;
                    else cout << ' ';
                    cout << it.first;
                }
            }
            cout << endl;
        }
        else { // c == ’L’
            if (M.empty()) cout << "NO LAST NIF" << endl;
            else {
                auto it = M.end();
                --it;
                cout << (*it).first << ' ' << (*it).second << endl;
            }
        }
    }
}