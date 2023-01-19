#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector< vector<char> > Map;
typedef pair<int, int> Position;
typedef pair<Position, int> Cell;


void readMap(Map& map, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> map[i][j];
    }
}

int bfs(Map& map, int x, int y) {
    // four directions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    // cell position (x, y) and distance from source
    queue<Cell> q;
    // initial pos with distance 0 into q
    Cell cell;
    cell.first.first = x;
    cell.first.second = y;
    cell.second = 0;
    q.push(cell);

    while (not q.empty()) {
        cell = q.front();
        q.pop();
        x = cell.first.first;
        y = cell.first.second;
        int distance = cell.second;
        if (map[x][y] == 't') return distance;
        map[x][y] = 'X';
        // check four directions
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (0 <= new_x and new_x < map.size() and 0 <= new_y and new_y < map[0].size() and map[new_x][new_y] != 'X') {
                cell.first.first = new_x;
                cell.first.second = new_y;
                cell.second = distance + 1;
                q.push(cell);
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    Map map(n, vector<char>(m));
    readMap(map, n, m);

    int x, y;
    cin >> x >> y;

    int min = bfs(map, x-1, y-1);
    if (min == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << min << endl;
}