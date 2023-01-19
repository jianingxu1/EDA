#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool isTwoColorable(const vector< vector<int> >& edges, vector<bool>& visited, vector<bool>& colors, int vertice, int parent, bool color) {
    visited[vertice] = true;
    colors[vertice] = color;
    for (auto edge : edges[vertice]) {
        if (not visited[edge]) {
            if (not isTwoColorable(edges, visited, colors, edge, vertice, not color)) return false;
        }
        else if (edge != parent and colors[edge] == colors[vertice]) return false;
    }
    return true;
}

bool isTwoColorable(const vector< vector<int> >& edges) {
    int n = edges.size();
    vector<bool> visited(n, false);
    vector<bool> colors(n, false);
    for (int i = 0; i < n; ++i) {
        if (not visited[i] and not isTwoColorable(edges, visited, colors, i, -1, false)) return false;
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        // read edges into adjacency list
        vector< vector<int> > edges(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        if (isTwoColorable(edges)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}