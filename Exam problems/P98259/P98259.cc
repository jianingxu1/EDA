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
typedef vector<VC> VVC;
typedef pair<int, int> PI;
typedef vector<string> VS;

int verDir[4] = {-1, 1, 0, 0};
int horDir[4] = {0, 0, -1, 1};
int n, m;
VVC board;
bool isInside;

bool isOk(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m and board[i][j] != '#';
}

void readBoard() {
    board = VVC(n, VC(m));
    isInside = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'T') isInside = true;
        }
    }
}

struct Pos {
    int i;
    int j;
};

// struct Compare {
    // bool operator() (const Pos& a, const Pos& b) {
        // if (a.steps != b.steps) return a.steps > b.steps;
        // else if (a.persons != b.persons) return a.persons < b.persons;
        // return true;
    // }
// };

void bfs() {
    VVI steps(n, VI(m, INT_MAX));
    VVI persons(n, VI(m, 0));
    queue<Pos> q;
    steps[0][0] = 0;
    persons[0][0] = 0;
    q.push({0, 0});

    Pos target;
    bool found = false;
    while (not q.empty()) {
        Pos p = q.front();
        q.pop();
        if (found and steps[p.i][p.j] + 1 > steps[target.i][target.j]) continue;
        int content = board[p.i][p.j];
        if (content == 'P') ++persons[p.i][p.j];
        else if (content == 'T') {
            target.i = p.i;
            target.j = p.j;
            found = true;
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int newI = p.i + verDir[i];
            int newJ = p.j + horDir[i];
            if (not isOk(newI, newJ)) continue;
            if (steps[p.i][p.j] + 1 > steps[newI][newJ]) continue;
            else if (steps[p.i][p.j] + 1 == steps[newI][newJ]) {
                if (persons[p.i][p.j] > persons[newI][newJ]) persons[newI][newJ] = persons[p.i][p.j];
                continue;
            }
            steps[newI][newJ] = steps[p.i][p.j] + 1;
            persons[newI][newJ] = persons[p.i][p.j];
            q.push({newI, newJ});
        }
    }
    if (found) cout << steps[target.i][target.j] << ' ' << persons[target.i][target.j] << endl;
    else cout << "The telecos is hidden." << endl;
}

int main() {
    while (cin >> n >> m) {
        readBoard();
        if (not isInside) {
            cout << "The telecos ran away." << endl;
            continue;
        }
        bfs();
    }

}