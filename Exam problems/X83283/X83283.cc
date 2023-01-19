#include <vector>
#include <list>
#include <iostream>
#include <queue>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef list<int> LI;

int maxVertex(const vector<LI>& adj) {
    int n = adj.size();
    VB vis(n, false);
    int maxDist = 0;
    int minVertex = 0;
    queue<pair<int, int>> q;
    vis[0] = true;
    q.push({0, 0});
    while (not q.empty()) {
        int v = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist > maxDist) {
            maxDist = dist;
            minVertex = v;
        }
        else if (dist == maxDist and v < minVertex) minVertex = v;
        for (auto neigh : adj[v]) {
            if (not vis[neigh]) {
                vis[neigh] = true;
                q.push({neigh, dist + 1});
            }
        }
    }
    return minVertex;
}

void readAdj(vector<LI>& adj, int m) {
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<LI> adj(n);
        readAdj(adj, m);
        cout << maxVertex(adj) << endl;
    }
}