#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<string> > Board;

void dfs(Board& board, int x, int y, int& sum, int& length) {
    ++length;
    sum += stoi(board[x][y]);
    board[x][y] = "X";
    if (x - 1 >= 0 and y - 1 >= 0) {
        if (board[x-1][y-1] != "X") dfs(board, x-1, y-1, sum, length);
    }
    // top-right
    if (x - 1 >= 0 and y + 1 < board[0].size()) {
        if (board[x-1][y+1] != "X") dfs(board, x-1, y+1, sum, length);
    }
    // bottom-left
    if (x + 1 < board.size() and y - 1 >= 0) {
        if (board[x+1][y-1] != "X") dfs(board, x+1, y-1, sum, length);
    }
    // bottom-right
    if (x + 1 < board.size() and y + 1 < board[0].size()) {
        if (board[x+1][y+1] != "X") dfs(board, x+1, y+1, sum, length);
    }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        // read board
        int n, m;
        cin >> n >> m;
        Board board(n, vector<string>(m));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) cin >> board[j][k];
        }

        int n_bishops;
        bool first = true;
        bool isDistributable = true;
        for (int j = 0; j < n and isDistributable; ++j) {
            for (int k = 0; k < m and isDistributable; ++k) {
                int sum = 0;
                int length = 0;
                if (board[j][k] != "X") {
                    // get the total number of bishops in the dfs and the number of nodes
                    dfs(board, j, k, sum, length);
                    if (sum%length != 0) isDistributable = false;
                    if (first) {
                        n_bishops = sum/length;
                        first = false;
                    }
                    else if (n_bishops != sum/length) isDistributable = false;
                }
            }
        }
        if (not isDistributable) cout << "Case " << i + 1 << ": no" << endl;
        else cout << "Case " << i + 1 << ": yes" << endl;
    }
}