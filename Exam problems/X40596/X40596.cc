#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef pair<int, int> PI;

class Balanced {
public:
    Balanced(int n, int d) {
        this->n = n;
        this->d = d;
        used = VB(n, false);
    }
    void solve() {
        backtracking(0);
    }
private:
    int n;
    int d;
    VB used;
    VI sol;
    void printSol() {
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << ',';
            cout << sol[i];
        }
        cout << ')' << endl;
    }
    void backtracking(int k) {
        if (k == n) {
            printSol();
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            // suma amb anterior es > d
            if (k != 0 and abs(sol[k-1] - (i + 1)) > d) continue;
            used[i] = true;
            sol.push_back(i + 1);
            backtracking(k + 1);
            sol.pop_back();
            used[i] = false;
        }
    }
};
int main() {
    int n, d;
    cin >> n >> d;
    Balanced sol(n, d);
    sol.solve();
}