#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;

class NQueens {
public:
    NQueens(int n);
    void solve();
private:
    int n;
    VB colIsAttacked;
    VB diagIsAttacked;
    VB adiagIsAttacked;
    VI queenPos;
    void printSol();
    void backtrack(int k);
};

NQueens::NQueens(int n) {
    this->n = n;
    queenPos = VI(n);
    colIsAttacked = VB(n, false);
    diagIsAttacked = VB(2*n-1, false);
    adiagIsAttacked = VB(2*n-1, false);
}

void NQueens::printSol() {
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (queenPos[row] == col) cout << 'Q';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

void NQueens::backtrack(int k) {
    if (k == n) printSol();
    else {
        for (int i = 0; i < n; ++i) {
            if (not colIsAttacked[i] and not diagIsAttacked[n - 1 + k - i] and not adiagIsAttacked[n - 1 + k + i]) {
                queenPos[k] = i;
                colIsAttacked[i] = true;
                diagIsAttacked[n - 1 + k - i] = true;
                adiagIsAttacked[n - 1 + k + i] = true;
                backtrack(k + 1);
                colIsAttacked[i] = false;
                diagIsAttacked[n - 1 + k - i] = false;
                adiagIsAttacked[n - 1 + k + i] = false;
            }
        }
    }
}
void NQueens::solve() {
    backtrack(0);
}

int main() {
    int n;
    cin >> n;
    NQueens sol(n);
    sol.solve();
}