#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef pair<int, int> PI;
typedef vector<string> VS;

struct Pos {
    int i;
    int j;
};

void readTargets(vector<Pos>& targets, int k) {
    for (int i = 0; i < k; ++i) {
        Pos p;
        cin >> p.i >> p.j;
        targets[i] = p;
    }
}

bool isOk(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

int jumpsNeeded(const Pos& ini, const Pos& target, int n, int m) {
    Pos possMoves[8] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
    queue<Pos> q;
    VVI dist(n, VI(m, -1));
    dist[ini.i][ini.j] = 0;
    q.push(ini);
    while (not q.empty()) {
        Pos p = q.front();
        int jumps = dist[p.i][p.j];
        q.pop();
        if (p.i == target.i and p.j == target.j) return jumps;
        for (int l = 0; l < 8; ++l) {
            int i = p.i + possMoves[l].i;
            int j = p.j + possMoves[l].j;
            if (not isOk(i, j, n, m) or dist[i][j] != -1) continue;
            dist[i][j] = jumps + 1;
            q.push({i, j});
        }
    }
    return -1;
}

int main() {
    int n, m, w, l, k;
    while (cin >> n >> m >> w >> l >> k) {
        vector<Pos> targets(k);
        readTargets(targets, k);

        vector<Pos> initialPos(k);
        initialPos[0] = {0, 0};
        for (int i = 0; i < k - 1; ++i) initialPos[i + 1] = targets[i];

        bool ok = true;
        int points = 0;
        int bestPoints = 0;
        for (int i = 0; i < k and ok; ++i) {
            int jumps = jumpsNeeded(initialPos[i], targets[i], n, m);
            if (jumps == -1) ok = false;
            else points = points - l*jumps + w;
            if (points > bestPoints) bestPoints = points;
        }
        cout << bestPoints << endl;
    }
}