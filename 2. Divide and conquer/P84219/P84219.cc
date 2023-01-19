#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v) {
    int l = 0, r = v.size() - 1;
    int index = -1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (v[m] == x) {
            index = m;
            r = m - 1;
        }
        else if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return index;
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << first_occurrence(2, v) << endl;
}