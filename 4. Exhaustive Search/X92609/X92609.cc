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
    int count;
    VB usedCoins;

    void printSol() const;
    void backtrack(int sum, int k);
};

void Coins::printSol() const {
    cout << count << endl;
}

Coins::Coins(int x, int n) {
    this->n = n;
    total = x;
    coins = VI(n);
    usedCoins = VB(n, false);
    count = 0;
    for (int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());
}

void Coins::backtrack(int sum, int k) {
    if (sum == total) {
        ++count;
        return;
    }
    for (int i = k; i < n; ++i) {
        int newSum = sum + coins[i];
        if (newSum <= total) {
            if (not usedCoins[i]) {
                usedCoins[i] = true;
                backtrack(newSum, i);
            }
            else {
                backtrack(newSum, i+1);
            }
            usedCoins[i] = false;
        }
    }
}

void Coins::solve() {
    backtrack(0, 0);
    printSol();
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        Coins sol(x, n);
        sol.solve();
    }
}