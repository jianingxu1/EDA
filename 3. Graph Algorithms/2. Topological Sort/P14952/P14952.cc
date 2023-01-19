#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

list<int> topological_sort(const vector< list<int> >& adj, vector<int>& indegrees) {
    int n = adj.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    // we want to start with the smallest vertice with indegree 0
    // (bc of the definition of lexicographical topological sort, if a vertice is indegree 0, it has no precedence vertices)
    // put all vertices with indegree 0 to priority queue
    for (int i = 0; i < n; ++i) {
        if (indegrees[i] == 0) pq.push(i);
    }
    // list to store the topological order
    list<int> l;
    while(not pq.empty()) {
        int v = pq.top();
        pq.pop();
        l.push_back(v);
        // visit all its neighbour vertices and lower their indegrees
        for (list<int>::const_iterator x = adj[v].begin(); x != adj[v].end(); ++x) {
            --indegrees[*x];
            // if indegree is 0, they no longer have any precedence left, so add
            // them to pq to then, visit its neighbour vertices
            if (indegrees[*x] == 0) pq.push(*x);
        }
    }
    return l;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector< list<int> > adj(n);
        // vector to store indegrees of all vertices
        // initialize all indegrees to 0
        vector<int> indegrees(n, 0);
        // read graph and indegrees of each vertex
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            ++indegrees[y];
        }

        // get the lexicographically topological order
        list<int> top_sort = topological_sort(adj, indegrees);

        // print
        bool first = true;
        for (list<int>::const_iterator i = top_sort.begin(); i != top_sort.end(); ++i) {
            if (first) {
                cout << *i;
                first = false;
            }
            else cout << ' ' << *i;
        }
        cout << endl;
    }
}