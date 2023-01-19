#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;

class Coins {
public: 
    Coins(int x, int n);
    void solve();
private:
    int n;
    int total;
    VI coins;
    vector<pair<int, bool>> solution;

    void printSol() const;
    void backtrack(int sum, int k);
};

void Coins::printSol() const {
    set<int> s;
    cout << total << " = ";
    for (int i = 0; i < solution.size(); ++i) {
        if (i != 0) cout << " + ";
        cout << solution[i].first;
        if (not solution[i].second) cout << 'p';
    }
    cout << endl;
}

Coins::Coins(int x, int n) {
    this->n = 2*n;
    total = x;
    coins = VI(2*n);
    for (int i = 0; i < 2*n; i += 2) {
        cin >> coins[i];
        coins[i+1] = coins[i];
    }
    sort(coins.begin(), coins.end());
}

void Coins::backtrack(int sum, int k) {
    if (sum == total) {
        printSol();
        return;
    }
    for (int i = k; i < n; ++i) {
        int newSum = sum + coins[i];
        if (newSum <= total) {
            solution.push_back({coins[i], i%2 == 0});
            backtrack(newSum, i + 1);
            solution.pop_back();
        }
    }
}

void Coins::solve() {
    backtrack(0, 0);
    cout << "----------" << endl;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        Coins sol(x, n);
        sol.solve();
    }
}