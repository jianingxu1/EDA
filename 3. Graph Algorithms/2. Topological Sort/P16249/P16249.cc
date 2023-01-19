#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

bool topological_sort(const vector< list<string> >& adj, unordered_map<string, int>& indexes, unordered_map<int, string>& words, vector<int>& indegrees, list<string>& topo_order) {
    priority_queue<string, vector<string>, greater<string> > pq;
    int n = adj.size();
    // add all vertices with indegree 0 to priority queue
    for (int i = 0; i < n; ++i) {
        if (indegrees[i] == 0) pq.push(words[i]);
    }
    
    int countVisitedVertices = 0;
    while (not pq.empty()) {
        // pq's top element is the lexicographically smallest from the vertices that have indegree 0 <-> vertices that we can visit
        string v = pq.top();
        pq.pop();
        topo_order.push_back(v);
        ++countVisitedVertices;
        // check all its neighbours
        for (auto x : adj[indexes[v]]) {
            // if its indegree is 0, we can visit it, so add it to pq
            if (--indegrees[indexes[x]] == 0) pq.push(x);
        }
    }
    if (countVisitedVertices != n) return false;
    return true; 
}

int main() {
    int n;
    while(cin >> n) {
        // read all words
        // map each word to a index (0 to n-1)
        unordered_map<string, int> indexes;
        unordered_map<int, string> words;
        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;
            indexes.insert(make_pair(word, i));
            words.insert(make_pair(i, word));
        }

        int m;
        cin >> m;
        vector<int> indegrees(n, 0);
        vector< list<string> > adj(n);
        // read adjacency list with strings
        for (int i = 0; i < m; ++i) {
            string x, y;
            cin >> x >> y;
            adj[indexes[x]].push_back(y);
            // count indegrees
            ++indegrees[indexes[y]];
        }
        list<string> topo_order;
        if (topological_sort(adj, indexes, words, indegrees, topo_order)) {
            for (auto w : topo_order) cout << w;
            cout << endl;
        }
        else cout << "NO VALID ORDERING" << endl;
    }
}