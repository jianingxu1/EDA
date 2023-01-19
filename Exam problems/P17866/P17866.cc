#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;

int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

int f, c;
VVC board;

void readBoard() {
    board = VVC(f, VC(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> board[i][j];
        }
    }
}

bool isOk(int i, int j) {
    return i >= 0 and i < f and j >= 0 and j < c and board[i][j] != 'X';
}

int bfs(int x, int y) {
    VVI steps(f, VI(c, -1));
    queue<PI> q;
    steps[x][y] = 0;
    q.push({x, y});
    while (not q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (board[i][j] == 'p') return steps[i][j];
        for (int l = 0; l < 8; ++l) {
            int newI = i + dirs[l][0];
            int newJ = j + dirs[l][1];
            if (isOk(newI, newJ) and steps[newI][newJ] == -1) {
                steps[newI][newJ] = steps[i][j] + 1;
                q.push({newI, newJ});
            }
        }
    }
    return -1;
}

int main() {

    while (cin >> f >> c) {
        readBoard();
        int x, y;
        cin >> x >> y;
        int steps = bfs(x - 1, y - 1);
        if (steps == -1) cout << "no" << endl;
        else cout << steps << endl;
    }
}
