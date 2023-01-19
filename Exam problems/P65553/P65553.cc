#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef pair<int, int> PI;
typedef vector<string> VS;

int main() {
    int n;
    while (cin >> n) {
        unordered_map<string, int> freq;
        // read initial collection
        int total = n;
        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;
            auto it = freq.find(type);
            if (it == freq.end()) freq.insert({type, 1});
            else ++((*it).second);
        }

        int g;
        cin >> g;
        for (int i = 0; i < g; ++i) {
            string type;
            cin >> type;

            auto it = freq.find(type);
            if (it == freq.end()) {
                freq.insert({type, 1});
                ++total;
            }
            else if (freq[type] + 1 <= total - freq[type]) {
                ++freq[type];
                ++total;
            }
        }

        map<string, int> sol;
        for (auto type : freq) {
            sol.insert({type.first, type.second});
        }

        // Print solution
        for (auto type : sol) {
            cout << type.first << ' ' << type.second << endl;
        }
        cout << "--------------------" << endl;
    }
}