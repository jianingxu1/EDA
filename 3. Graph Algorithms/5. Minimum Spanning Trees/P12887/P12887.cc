#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef list<PI> LPI;

int n, m;
vector<LPI> adj;

void readGraph() {
    for (int i = 0; i < m; ++i) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1 - 1].push_back({v2 - 1, cost});
        adj[v2 - 1].push_back({v1 - 1, cost});
    }
}

int getMST() {
    VB vis(n, false);
    VI cost(n, INT_MAX);
    // cost, vertex
    priority_queue<PI, vector<PI>, greater<PI>> q;
    q.push({0, 0});
    cost[0] = 0;
    while (not q.empty()) {
        // if not visited
        // mark as visited
        // visit all adj nodex
        // if not visited
        // if cost is lower
        // update cost
        // add to queue
        int v = q.top().second;
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto edge : adj[v]) {
            int u = edge.first;
            int c = edge.second;
            if (vis[u]) continue;
            if (c < cost[u]) {
                cost[u] = c;
                q.push({c, u});
            }
        }
    }
    int totalCost = 0;
    for (int i = 0; i < n; ++i) totalCost += cost[i];
    return totalCost;
}

int main() {
    while (cin >> n >> m) {
        adj = vector<LPI>(n);
        // Read graph
        readGraph();
        cout << getMST() << endl;
    }
}
