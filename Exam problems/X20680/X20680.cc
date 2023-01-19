#include <iostream>
#include <vector>
using namespace std;

class Letters {
public:
    Letters(int n, int c) {
        this->c = c;
        this->n = n;
    }
    void solve() {
        backtracking(0, 0);
        cout << "--------------------" << endl;
    }
private:
    int n;
    int c;
    vector<char> sol;
    char letters[3] = {'x', 'y', 'z'};
    void printSol() {
        for (int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
    }
    void backtracking(int k, int count) {
        if (k == n) {
            printSol();
            return;
        }
        for (int i = 0; i < 3; ++i) {
            char ch = letters[i];
            if (k == 0 or ch != sol[k - 1]) {
                sol.push_back(ch);
                backtracking(k + 1, 1);
                sol.pop_back();
            }
            else if (ch == sol[k - 1] and count < c) {
                sol.push_back(ch);
                backtracking(k + 1, count + 1);
                sol.pop_back();
            }
        }
    }
};

int main() {
    int n, c;
    while (cin >> n >> c) {
        Letters sol(n, c);
        sol.solve();
    }
}