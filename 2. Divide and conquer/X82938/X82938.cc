#include <iostream>
#include <vector>
using namespace std;

int find_unimodal(const vector<int>& v, int l, int r) {
    if (l == r) return r;
    if (r - l == 1) {
        if (v[l] > v[r]) return l;
        return r;
    }
    int m = l + (r - l)/2;
    // increase and decrease
    if (v[m] > v[m + 1] and v[m] > v[m - 1]) return m;
    // decreasing
    if (v[m - 1] > v[m]) return find_unimodal(v, l, m - 1);
    // increasing
    return find_unimodal(v, m + 1, r);
}

bool binary_search(int x, const vector<int>& v, int l, int r, int mode) {
    if (l > r) return false;
    int m = l + (r - l)/2;
    if (v[m] == x) return true;
    if ((x < v[m] and mode == 0) or (x > v[m] and mode == 1)) {
        return binary_search(x, v, l, m - 1, mode);
    }
    return binary_search(x, v, m + 1, r, mode);
}

bool search(int x, const vector<int>& v) {
    int unimodal_index = find_unimodal(v, 0, v.size() - 1);
    return binary_search(x, v, 0, unimodal_index, 0) or binary_search(x, v, unimodal_index + 1, v.size() - 1, 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int x;
    cin >> x;
    cout << search(x, v) << endl;
}