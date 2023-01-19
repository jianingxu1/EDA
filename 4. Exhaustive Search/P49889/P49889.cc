#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;

class Word {
public:
    Word(int n);
    void solve();
private:
    int n;
    VC vocal;
    VC consonant;
    VB vocalIsUsed;
    VB consonantIsUsed;
    VC solution;
    void printSol();
    void backtrack(int k, bool isConsonant);
};

Word::Word(int n) {
    this->n = n;
    consonant = VC(n);
    vocal = VC(n);
    for (int i = 0; i < n; ++i) cin >> consonant[i];
    for (int i = 0; i < n; ++i) cin >> vocal[i];
    consonantIsUsed = VB(n, false);
    vocalIsUsed = VB(n, false);
    solution = VC(2*n);
}

void Word::printSol() {
    for (int i = 0; i < 2*n; ++i) cout << solution[i];
    cout << endl;
}

void Word::backtrack(int k, bool isConsonant) {
    if (k == 2*n) printSol();
    else if (isConsonant) {
        for (int i = 0; i < n; ++i) {
            if (not consonantIsUsed[i]) {
                consonantIsUsed[i] = true;
                solution[k] = consonant[i];
                backtrack(k + 1, not isConsonant);
                consonantIsUsed[i] = false;
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (not vocalIsUsed[i]) {
                vocalIsUsed[i] = true;
                solution[k] = vocal[i];
                backtrack(k + 1, not isConsonant);
                vocalIsUsed[i] = false;
            }
        }
    }
}
void Word::solve() {
    backtrack(0, true);
}

int main() {
    int n;
    cin >> n;
    Word sol(n);
    sol.solve();
}