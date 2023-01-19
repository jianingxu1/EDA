#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v, int l, int r) {
    if (l > r) return -1;

    int m = l + (r - l)/2;
    if (x < v[m]) {
        if (m + 1 <= r and v[m + 1] == x) {
            int ans = first_occurrence(x, v, l, m - 1);
            if (ans != -1) return ans;
            else return m + 1;
        }
        return first_occurrence(x, v, l, m - 1);
    }
    else if (x > v[m]) {
        if (m - 1 >= l and v[m - 1] == x) return m - 1;
        return first_occurrence(x, v, m + 1, r);
    }
    else {
        int ans = first_occurrence(x, v, l, m - 1);
        if (ans != -1) return ans;
        return m;
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return first_occurrence(x, v, 0, v.size() - 1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}