#include <iostream>
#include <vector>
using namespace std;

class NZeroesAndOnes {
public:
    NZeroesAndOnes(int n, int o);
    void solve();
private:
    int n;
    int zeros;
    int ones;
    vector<bool> num;
    void printSol();
    void backtrack(int i, int numZeros);
};

NZeroesAndOnes::NZeroesAndOnes(int n, int o) {
    this->n = n;
    ones = o;
    this->zeros = n - o;
    num = vector<bool>(n);
}
void NZeroesAndOnes::printSol() {
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        if (num[i]) cout << '1';
        else cout << '0';
    }
    cout << endl;
}

void NZeroesAndOnes::backtrack(int i, int numZeros) {
    if (i == n) printSol();
    else {
        if (numZeros < zeros) {
            num[i] = false;
            backtrack(i+1, numZeros+1);
        }
        int numOnes = i - numZeros;
        if (numOnes < ones) {
            num[i] = true;
            backtrack(i+1, numZeros);
        }
    }
}
void NZeroesAndOnes::solve() {
    backtrack(0, 0);
}

int main() {
    int n, o;
    cin >> n >> o;
    NZeroesAndOnes sol(n, o);
    sol.solve();
}