#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v, int l, int r) {
    if (l > r) return false;
    else {
        int m = l + (r - l)/2;
        if (v[m] == x) return true;
        if (v[m] > x) {
            if (m + 1 <= r and v[m + 1] == x) return true;
            return resistant_search(x, v, l, m - 1);
        }
        else {
            if (m - 1 >= l and v[m - 1] == x) return true;
            return resistant_search(x, v, m + 1, r);
        }
    }
}

bool resistant_search(double x, const vector<double>& v) {
    return resistant_search(x, v, 0, v.size() - 1);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << resistant_search(x, v) << endl;
}