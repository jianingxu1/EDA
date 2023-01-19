#include <iostream>
#include <set>
using namespace std;

struct comp {
    bool operator()(const string& a, const string& b) const {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }
};

void printGame(int gameNum, const set<string>& S, const set<string, comp>& S2) {
    cout << "GAME #" << gameNum << endl;
    cout << "HAS:" << endl;
    for (auto w:S) cout << w << endl;
    cout << endl << "HAD:" << endl;
    for (auto w:S2) cout << w << endl;
}

int main() {
    set<string> S;
    set<string, comp> S2;

    int gameNum = 0;
    string w;
    cin >> w;
    while (w != "QUIT") {
        if (w != "END") {
            auto it = S.find(w);
            if (it == S.end()) {
                S.insert(w);
                auto it2 = S2.find(w);
                if (it2 != S2.end()) S2.erase(it2);
            }
            else {
                S.erase(it);
                S2.insert(w);
            }
        }
        else {
            printGame(++gameNum, S, S2);
            S.clear();
            S2.clear();
            cout << endl;
        }
        cin >> w;
    }
    printGame(++gameNum, S, S2);
}