#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<int, int> PII;

class NRooks {
private:
    int r;
    int c;
    VI colPos;
    VB colAttacked;
    void printSol() {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (colPos[i] == j) cout << 'R';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }
    void backtracking(int k) {
        if (k == r) {
            printSol();
            return;
        }
        for (int i = 0; i < c; ++i) {
            if (not colAttacked[i]) {
                colPos[k] = i;
                colAttacked[i] = true;
                backtracking(k + 1);
                colAttacked[i] = false;
            }
        }
    }

public:
    NRooks(int r, int c) {
        this->r = r;
        this->c = c;
        colPos = VI(r);
        colAttacked = VB(c, false);
    }
    void solve() {
        backtracking(0);
    }
};

int main() {
    int r, c;
    cin >> r >> c;
    NRooks sol(r, c);
    sol.solve();
}
