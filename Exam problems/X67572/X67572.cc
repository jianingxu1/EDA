#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

class NWords{
public:
    NWords(int n) {
        this->n = n;
        words = VS(n);
        isUsed = VB(n, false);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
    }
    void solve() {
        backtracking(0);
    }
private:
    int n;
    VS words;
    VB isUsed;
    VS sol;
    void printSol() {
        for (int i = 0; i < n; ++i) {
            cout << sol[i];
        }
        cout << endl;
    }
    void backtracking(int k) {
        if (k == n) {
            printSol();
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (not isUsed[i]) {
                string w = words[i];
                if (k == 0 or w[0] != sol[k-1][sol[k-1].size()-1]) {
                    isUsed[i] = true;
                    sol.push_back(w);
                    backtracking(k + 1);
                    sol.pop_back();
                    isUsed[i] = false;

                }
            }
        }
    }
};
int main() {
    // read n words
    // for each word
    // if start of word != end of word of previous
    // backtrack	
    int n;
    cin >> n;
    NWords sol(n);
    sol.solve();
}

