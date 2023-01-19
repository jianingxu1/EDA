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
typedef vector<bool> VB;
typedef vector<char> VC;
typedef pair<int, int> PI;

int n, m;
vector<list<PI>> adj;

void readGraph() {
    for (int i = 0; i < m; ++i) {
        int from, to, l;
        cin >> from >> to >> l;
        adj[from].push_back({to, l});
    }
}

int mst() {
    VB vis(n, false);
    VI prev(n, -1);
    VI cost(n, INT_MAX);
    priority_queue<PI, vector<PI>, greater<PI>> q;
    cost[0] = 0;
    q.push({0, 0});
    int dest = 1;
    while (not q.empty() and q.top().second != dest) {
        int v = q.top().second;
        // cout << v << ' ' << q.top().first << endl; 
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        // vis adjacent nodes
        // if vis or edge.cost >= cost[] continue
        for (auto edge : adj[v]) {
            int u = edge.first;
            int c = edge.second;
            if (vis[u] or c >= cost[u]) continue;
            cost[u] = c;
            prev[u] = v;
            q.push({c, u});
        }
    }
    int maxLength = 0;
    while (dest != 0) {
        if (cost[dest] > maxLength) maxLength = cost[dest];
        dest = prev[dest];
    }
    return maxLength;
}

int main() {
    while (cin >> n >> m) {
        adj = vector<list<PI>>(n);
        readGraph();
        cout << mst() << endl;
    }    
}