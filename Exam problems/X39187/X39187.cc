#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef pair<int, int> PI;
typedef vector<string> VS;

class Trans {
public:
    Trans(int n, int c) {
        this->n = n;
        coins = c;
        shares = 0;
    }
    void solve() {
        backtracking(0);
    }
private:
    int coins;
    int shares;
    int n;
    VC sol;
    void printSol() {
        for (int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
    }
    void backtracking(int k) {
        if (k == n) {
            printSol();
            return;
        }
        // buy share
        if (coins > 0) {
            --coins;
            ++shares;
            sol.push_back('b');
            backtracking(k + 1);
            sol.pop_back();
            ++coins;
            --shares;
        }
        if (shares > 0) {
            --shares;
            ++coins;
            sol.push_back('s');
            backtracking(k + 1);
            sol.pop_back();
            ++shares;
            --coins;
        }
    }
};

int main() {
    int n, c;
    cin >> n >> c;
    Trans sol(n, c);
    sol.solve();
}