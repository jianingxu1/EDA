#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<int, int> PII;

void dijkstra(const vector<list<PII>>& adj, int source, int dest) {
    int n = adj.size();
    VI dist(n, INT_MAX);
    VI ways(n, 0);
    VB visited(n, false);
    dist[source] = 0;
    ways[source] = 1;
    // distance, vertex
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, source});
    // if q.top().second is dest, then we have found the minimum cost to go to dest, so stop
    while (not q.empty() and q.top().second != dest) {
        int node = q.top().second;
        q.pop();
        if (not visited[node]) {
            visited[node] = true;
            for (auto edge : adj[node]) {
                int cost = dist[node] + edge.second;
                int toNode = edge.first;
                if (cost < dist[toNode]) {
                    dist[toNode] = cost;
                    ways[toNode] = ways[node];
                    q.push({cost, toNode});
                }
                else if (cost == dist[toNode]) ways[toNode] += ways[node];
            }
        }
    }
    if (dist[dest] == INT_MAX) {
        cout << "no path from " << source << " to " << dest << endl;
        return;
    }
    cout << "cost " << dist[dest] << ", " << ways[dest] << " way(s)" << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector< list<PII> > adj(n);
        for (int i = 0; i < m; ++i) {
            int from, to, cost;
            cin >> from >> to >> cost;
            adj[from].push_back({to, cost});
        }
        // source, destination
        int s, d;
        cin >> s >> d;
        dijkstra(adj, s, d);
    }
}