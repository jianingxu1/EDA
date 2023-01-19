#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <climits>
using namespace std;

struct directedEdge {
    int destEdge;
    int cost;
};

// n: number of vertices
int dijkstra(const vector< list<directedEdge> >& adj, int n, int source, int dest) {
    vector<bool> vis(n, false);
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // ordena de menor a major, primer per la distancia, i després pel num del vèrtex
    set< pair<int, int> > q;
    q.insert(make_pair(dist[source], source));

    while (not q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        vis[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.destEdge;
            int cost = dist[v] + edge.cost;
            if (cost < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = cost;
                q.insert({cost, to});
            }
        }
    }
    if (dist[dest] == INT_MAX) return -1;
    return dist[dest];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        // read adj
        vector< list<directedEdge> > adj(n);
        for (int i = 0; i < m; ++i) {
            int source;
            directedEdge e;
            cin >> source >> e.destEdge >> e.cost;
            adj[source].push_back(e);
        }
        // cout << "x" << endl;
        int s, d;
        cin >> s >> d;
        int distance = dijkstra(adj, n, s, d);
        // cout << "1" << endl;
        if (distance == -1) cout << "no path from " << s << " to " << d << endl;
        else cout << distance << endl;
    }
}