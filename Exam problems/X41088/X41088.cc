#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

class Wells {
    public:
        Wells(int n) {
            this->n = n;
            used = VB(n, false);
        }
        void solve() {
            backtracking(0);
        }
    private:
        int n;
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
                if (not used[i] and (k == 0 or k == 1 or sol[k-2] + i + 1 <= 2*sol[k-1])) {
                    used[i] = true;
                    sol.push_back(i+1);
                    backtracking(k + 1);
                    sol.pop_back();
                    used[i] = false;
                }
            }
        }
};
int main() {
    int n;
    cin >> n;
    Wells sol(n);
    sol.solve();
}
