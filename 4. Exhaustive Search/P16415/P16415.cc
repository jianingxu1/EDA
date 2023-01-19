#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;

class NQueens {
public:
    NQueens(int n);
    void solve();
private:
    int n;
    int sol;
    VB colIsAttacked;
    VB diagIsAttacked;
    VB adiagIsAttacked;
    void backtrack(int k);
};

NQueens::NQueens(int n) {
    this->n = n;
    colIsAttacked = VB(n, false);
    diagIsAttacked = VB(2*n-1, false);
    adiagIsAttacked = VB(2*n-1, false);
    sol = 0;
}

void NQueens::backtrack(int k) {
    if (k == n) ++sol;
    else {
        for (int i = 0; i < n; ++i) {
            if (not colIsAttacked[i] and not diagIsAttacked[n - 1 + k - i] and not adiagIsAttacked[n - 1 + k + i]) {
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
    cout << sol << endl;
}

int main() {
    int n;
    cin >> n;
    NQueens sol(n);
    sol.solve();
}