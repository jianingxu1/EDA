#include <iostream>
using namespace std;

int expo(int n, int k, int m) {
    if (n == 0) return 0;
    if (k == 0) return 1;
    if (k%2 == 0) {
        int x = expo(n, k/2, m);
        return (x*x)%m;
    }
    else return ((n%m)*expo(n, k-1, m))%m;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        cout << expo(n, k, m) << endl;
    }
}