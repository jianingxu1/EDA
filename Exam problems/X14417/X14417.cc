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
typedef vector<bool> VB;
typedef vector<char> VC;
typedef pair<int, int> PI;
typedef vector<string> VS;

struct Pos {
    int clicks;
    int i;
    int j;
};

struct comparePos {
    bool operator() (const Pos& a, const Pos& b) {
        if (a.clicks != b.clicks) return a.clicks >= b.clicks;
        return true;
    }
};

int verDir[4] = {-1, 1, 0, 0};
int horDir[4] = {0, 0, -1, 1};

int n, m, p;
vector<VS> board;
VS words;
unordered_set<string> allWords;

void readBoard() {
    board = vector<VS>(n, VS(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            allWords.insert(board[i][j]);
        }
    }
}

void readWords() {
    cin >> p;
    words = VS(p);
    for (int i = 0; i < p; ++i) {
        cin >> words[i];
    }
}

// order by i (words clicked), clicks, prev pos
// check when enter

// impossible if clicks == n*m and i == 0

bool isOk(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

int bfs() {
    // vector<VB> vis(n, VB(m, false));
    for (int l = 0; l < p; ++l) {
        if (allWords.find(words[l]) == allWords.end()) {
            return -1;
        }
    }
    vector<VB> vis(n, VB(m, false));
    queue<Pos> q;
    q.push({0, 0, 0});
    int k = 0;
    int totalClicks = 0;
    while (not q.empty() and k < p) {
        int clicks = q.front().clicks;
        int i = q.front().i;
        int j = q.front().j;
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (board[i][j] == words[k]) {
            totalClicks += clicks + 1;
            ++k;
            vis = vector<VB>(n, VB(m, false));
            while (not q.empty()) q.pop();
            q.push({0, i, j});
            continue;
        }
        for (int l = 0; l < 4; ++l) {
            int newI = i + verDir[l];
            int newJ = j + horDir[l];
            if (not isOk(newI, newJ) or vis[newI][newJ] or board[newI][newJ] == "*") continue;
            q.push({clicks + 1, newI, newJ});
        }
        }
    if (k == p) return totalClicks;
    return -1;
}

int main() {
    while (cin >> n >> m) {
        // read board
        readBoard();
        readWords();
        int totalClicks = bfs();
        if (totalClicks == -1) cout << "impossible" << endl;
        else cout << totalClicks << endl;
    }
}