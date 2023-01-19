#include <iostream>
#include <vector>
using namespace std;

class Permutations {
public:
    Permutations(int n);
    void solve();
private:
    int n;
    vector<string> sol;
    vector<string> words;
    vector<bool> wordIsUsed;
    void printPermutation() const;
    void backtrack(int i);
};

Permutations::Permutations(int n) {
    this->n = n;
    sol = vector<string>(n);
    words = vector<string>(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    wordIsUsed = vector<bool>(n, false);
}

void Permutations::printPermutation() const {
    cout << '(';
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ',';
        cout << sol[i];
    }
    cout << ')' << endl;
}

void Permutations::backtrack(int i) {
    if (i == n) printPermutation();
    else {
        for (int k = 0; k < n; ++k) {
            if (not wordIsUsed[k]) {
                wordIsUsed[k] = true;
                sol[i] = words[k];
                backtrack(i+1);
                wordIsUsed[k] = false;
            }
        }
    }
}

void Permutations::solve() {
    backtrack(0);
}

int main() {
    int n;
    cin >> n;
    Permutations sol(n);
    sol.solve();
}