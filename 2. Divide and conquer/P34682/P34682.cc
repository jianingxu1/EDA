#include <iostream>
#include <vector>
using namespace std;

int fixed_point(const vector<int>& v, int a, int l, int r) {
    if (l > r) return -1;
    int m = l + (r - l)/2;
    if (v[m] + a == m + 1) {
        int left_ans = fixed_point(v, a, l, m - 1);
        if (left_ans == -1) return m + 1;
        return left_ans;
    }
    else if (v[m] + a > m + 1) return fixed_point(v, a, l, m - 1);
    else return fixed_point(v, a, m + 1, r);
}

int fixed_point(const vector<int>&v, int a) {
    return fixed_point(v, a, 0, v.size() - 1);
}

int main() {
    int n;
    int seq = 0;
    while (cin >> n) {
        ++seq;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int m;
        cin >> m;
        cout << "Sequence #" << seq << endl;
        for (int j = 1; j <= m; ++j) {
            int a;
            cin >> a;
            int index = fixed_point(v, a);
            if (index != -1) cout << "fixed point for " << a << ": " << index << endl;
            else cout << "no fixed point for " << a << endl;
        }
        cout << endl;
    } 
}