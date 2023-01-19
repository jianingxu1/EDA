#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Map;

void readMap(Map& map, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> map[i][j];
        }
    }
}

int treasuresReachable(Map& map, int row, int col) {
    int rows = map.size();
    int cols = map[0].size();
    map[row][col] = 'X';
    int treasures = 0;
    // go up
    if (row - 1 >= 0) {
        if (map[row - 1][col] != 'X') {
            if (map[row-1][col] == 't') treasures += 1;
            treasures += treasuresReachable(map, row - 1, col);
        }
    }
    // go left
    if (col - 1 >= 0) {
        if (map[row][col - 1] != 'X') {
            if (map[row][col - 1] == 't') treasures += 1;
            treasures += treasuresReachable(map, row, col - 1);
        }
    }
    // go right
    if (col + 1 < cols) {
        if (map[row][col + 1] != 'X') {
            if (map[row][col + 1] == 't') treasures += 1;
            treasures += treasuresReachable(map, row, col + 1);
        }
    }
    // down
    if (row + 1 < rows) {
        if (map[row + 1][col] != 'X') {
            if (map[row+1][col] == 't') treasures += 1;
            treasures += treasuresReachable(map, row + 1, col);
        }
    }
    return treasures;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Map treasure_map(rows, vector<char>(cols));
    readMap(treasure_map, rows, cols);

    int x, y;
    cin >> x >> y;
    cout << treasuresReachable(treasure_map, x - 1, y - 1) << endl;
}