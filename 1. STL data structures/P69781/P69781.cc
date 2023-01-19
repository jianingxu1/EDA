#include <iostream>
#include <unordered_map>
using namespace std;

const int LIMIT = 1e8;

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        bool hasCycle = false;
        unordered_map<int, int> freq;
        freq.insert({n, 1});
        int cycleLength = 0;
        while (n <= LIMIT and not hasCycle) {
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            auto it = freq.find(n);
            if (it == freq.end()) freq.insert(it, {n, 1});
            else {
                ++(it->second);
                ++cycleLength;
            }
            
            if (it != freq.end() and it->second == 3) hasCycle = true;
        }
        if (hasCycle) cout << cycleLength - 1 << endl;
        else cout << n << endl;
    }
}