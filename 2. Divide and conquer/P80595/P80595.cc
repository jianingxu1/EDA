#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>&v, int l, int m, int r) {
    // Size of left vector
    int n1 = m - l + 1;
    // Size of right vector
    int n2 = r - (m + 1) + 1;
    // Create copy of left and right vectors
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; ++i) left[i] = v[i + l];
    for (int i = 0; i < n2; ++i) right[i] = v[i + m + 1];
    int count_inversions = 0;
    int index_left = 0;
    int index_right = 0;
    int index_merged = l;

    while (index_left < n1 and index_right < n2) {
        if (left[index_left] <= right[index_right]) {
            v[index_merged] = left[index_left];
            ++index_left;
        }
        else {
            v[index_merged] = right[index_right];
            count_inversions = count_inversions + (n1 - index_left); 
            ++index_right;
        }
        ++index_merged;
    }
    while (index_left < n1) {
        v[index_merged] = left[index_left];
        ++index_left;
        ++index_merged;
    }
    while (index_right < n2) {
        v[index_merged] = right[index_right];
        ++index_right;
        ++index_merged;
    }
    return count_inversions;
}

int countInversions(vector<int>& v, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l)/2;
    int count_inversions = countInversions(v, l, m) + countInversions(v, m + 1, r);
    count_inversions += merge(v, l, m, r);
    return count_inversions;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        cout << countInversions(v, 0, v.size() - 1) << endl;
    }
}