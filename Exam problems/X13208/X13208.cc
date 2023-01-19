#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

struct Cell {
    int i;
    int j;
    int dist;
};

struct CellComp {
    bool operator() (const Cell& a, const Cell& b) {
        if (a.dist != b.dist) return a.dist >= b.dist;   // prio_queue, priority is lower
        return true;
    }
};

bool isInside(int n, int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < n;
}

int getMinCost(const vector<VI>& cost, int n) {
    vector<VB> vis(n, VB(n, false));
    vector<VI> dis(n, VI(n, INT_MAX));
    int horDir[4] = {-1, 1, 0, 0};
    int verDir[4] = {0, 0, -1, 1};
    priority_queue<Cell, vector<Cell>, CellComp> q;
    int m = n/2;
    dis[m][m] = cost[m][m];
    q.push({m, m, cost[m][m]});
    while (not q.empty()) {
        int i = q.top().i;
        int j = q.top().j;
        int dist = q.top().dist;
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int newI = i + horDir[k];
            int newJ = j + verDir[k];
            if (not isInside(n, newI, newJ)) continue;
            int newDist = dist + cost[newI][newJ];
            if (newDist < dis[newI][newJ]) {
                dis[newI][newJ] = newDist;
                q.push({newI, newJ, newDist});
            }
        }
    }
    bool found = false;
    int min;
    for (int i = 0; i < n; ++i) {
        if (not found) {
            min = dis[0][i];
            found = true;
        }
        if (dis[0][i] < min) min = dis[0][i];
        if (dis[n - 1][i] < min) min = dis[n - 1][i];
        if (dis[i][0] < min) min = dis[i][0];
        if (dis[i][n - 1] < min) min = dis[i][n-1];
    }
    return min;
}

int main() {
    int n;
    while (cin >> n) {
        vector<VI> cost(n, VI(n));
        // read costs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> cost[i][j];
            }
        }
        cout << getMinCost(cost, n) << endl;
    }
}

