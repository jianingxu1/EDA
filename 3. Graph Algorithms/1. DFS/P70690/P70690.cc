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

bool isTreasureReachable(Map& map, int row, int col) {
    int rows = map.size();
    int cols = map[0].size();
    map[row][col] = 'X';
    // go up
    if (row - 1 >= 0) {
        if (map[row - 1][col] == 't' or (map[row - 1][col] == '.' and isTreasureReachable(map, row - 1, col))) return true;
    }
    // go left
    if (col - 1 >= 0) {
        if (map[row][col - 1] == 't' or (map[row][col - 1] == '.' and isTreasureReachable(map, row, col - 1))) return true; 
    }
    // go right
    if (col + 1 < cols) {
        if (map[row][col + 1] == 't' or (map[row][col + 1] == '.' and isTreasureReachable(map, row, col + 1))) return true;
    }
    // down
    if (row + 1 < rows) {
        if (map[row + 1][col] == 't' or (map[row + 1][col] == '.' and isTreasureReachable(map, row + 1, col))) return true;
    }
    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Map treasure_map(rows, vector<char>(cols));
    readMap(treasure_map, rows, cols);

    int x, y;
    cin >> x >> y;
    if (isTreasureReachable(treasure_map, x - 1, y - 1)) cout << "yes" << endl;
    else cout << "no" << endl;
}