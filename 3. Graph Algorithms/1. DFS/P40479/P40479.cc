#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Board;

void dfs(Board& board, int x, int y, char value) {
    if (board[x][y] != '#' and board[x][y] != value) {
        if (board[x][y] == '.') board[x][y] = value;
        // up
        if (x-1 >= 0) dfs(board, x-1, y, board[x][y]);
        // down
        if (x+1 < board.size()) dfs(board, x+1, y, board[x][y]);
        // left
        if (y-1 >= 0) dfs(board, x, y-1, board[x][y]);
        // right
        if (y+1 < board[0].size()) dfs(board, x, y+1, board[x][y]);
    }
}

void readBoard(Board& board, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> board[i][j];
    }
}

void printBoard(const Board& board, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << board[i][j];
        cout << endl;
    }
    cout << endl;
}
int main() {
    int n, m;
    while (cin >> n >> m) {
        Board board(n, vector<char>(m));
        readBoard(board, n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != '#' and board[i][j] != '.') {
                    dfs(board, i, j, '.');
                }
            }
        }   
        printBoard(board, n, m);
    }
}