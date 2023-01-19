#include <iostream>
#include <vector>
using namespace std;

class NZeroesAndOnes {
public:
    NZeroesAndOnes(int n);
    void solve();
private:
    int n;
    vector<bool> num;
    void printSol();
    void backtrack(int i);
};

NZeroesAndOnes::NZeroesAndOnes(int n) {
    this->n = n;
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

void NZeroesAndOnes::backtrack(int i) {
    if (i == n) printSol();
    else {
        num[i] = false;
        backtrack(i+1);
        num[i] = true;
        backtrack(i+1);
    }
}
void NZeroesAndOnes::solve() {
    backtrack(0);
}

int main() {
    int n;
    cin >> n;
    NZeroesAndOnes sol(n);
    sol.solve();
}