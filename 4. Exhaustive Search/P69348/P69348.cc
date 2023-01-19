#include <iostream>
#include <vector>
using namespace std;

class Permutations {
public:
    Permutations(int n);
    void solve();
private:
    int n;
    vector<int> sol;
    vector<bool> numTaken;
    void printPermutation() const;
    void backtrack(int i);
};

Permutations::Permutations(int n) {
    this->n = n;
    sol = vector<int>(n);
    numTaken = vector<bool>(n, false);
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
            if (not numTaken[k]) {
                numTaken[k] = true;
                sol[i] = k+1;
                backtrack(i+1);
                numTaken[k] = false;
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