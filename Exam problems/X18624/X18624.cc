#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<char> VC;

class Words {
public:
    Words(int n, int m) {
        this->n = n;
        this->m = m;
        letters = VC(m);
        for (int i = 0; i < m; ++i) cin >> letters[i];
        sort(letters.begin(), letters.end());
    }

    void solve() {
        backtracking(0);
        cout << "----------" << endl;
    }

private:
    int n;
    int m;
    VC letters;
    VC sol;

    void printSol() {
        for (int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
    }

    bool isVowel(char c) {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
            return true;
        }
        return false;
    }

    void backtracking(int k) {
        if (k == n) {
            printSol();
            return;
        }
        for (int i = 0; i < m; ++i) {
            char c = letters[i];
            if (k == 0 or (not isVowel(c)) or (not isVowel(sol[k - 1]))) {
                sol.push_back(c);
                backtracking(k + 1);
                sol.pop_back();
            }
        }
    }
};


int main() {
    // for each letter
    // if is vowel and prevLetter is not vowel
    //  or is not vowel or k == 0
    int n, m;
    while (cin >> n >> m) {
        Words sol(n, m);
        sol.solve();
    }
}