#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

struct directedEdge {
    int to;
    int cost;
};

void dijkstra(const vector< list<directedEdge> >& adj, int n, int source, int dest) {
    vector<int> prevNode(n, -1);
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, source});

    while (not q.empty() and q.top().second != dest) {
        int v = q.top().second;
        q.pop();
        if (not visited[v]) {
            visited[v] = true;
            for (auto edge : adj[v]) {
                int cost = dist[v] + edge.cost;
                int to = edge.to;
                if (cost < dist[to]) {
                    dist[to] = cost;
                    prevNode[to] = v;
                    q.push({cost, to});
                }
            }
        }
    }
    if (dist[dest] == INT_MAX) {
        cout << "no path from " << source << " to " << dest << endl;
        return;
    }

    stack<int> s;
    int v = dest;
    while (v != source) {
        s.push(v);
        v = prevNode[v];
    } 
    s.push(v);

    cout << s.top();
    s.pop();
    while (not s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        // read adj
        vector< list<directedEdge> > adj(n);
        for (int i = 0; i < m; ++i) {
            int source;
            directedEdge e;
            cin >> source >> e.to >> e.cost;
            adj[source].push_back(e);
        }
        int source, dest;
        cin >> source >> dest;
        dijkstra(adj, n, source, dest);
    }
}