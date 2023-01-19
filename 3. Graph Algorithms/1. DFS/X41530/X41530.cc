#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool dfs(vector<bool>& visited, const vector< vector<int> >& edges, int vertice, int parent) {
    visited[vertice] = true;
    for (auto edge : edges[vertice]) {
        if (not visited[edge]) {
            if (dfs(visited, edges, edge, vertice)) return true;
        }
        else if (edge != parent) return true;
    }
    return false;
}

void isForest(vector<bool>& visited, const vector< vector<int> >& edges) {
    bool hasCycle = false;
    int countTrees = 0;
    for (int i = 0; i < visited.size() and not hasCycle; ++i) {
        if (!visited[i]) {
            hasCycle = dfs(visited, edges, i, i);
            if (not hasCycle) ++countTrees;
        }
    }
    if (hasCycle) cout << "no" << endl;
    else cout << countTrees << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<bool> visited(n, false);

        // read edges into adjacency list
        vector< vector<int> > edges(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        isForest(visited, edges);
    }
}