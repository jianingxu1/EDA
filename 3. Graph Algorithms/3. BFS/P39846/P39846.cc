#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector< vector<char> > Map;

int treasures = 0;

struct Cell {
    int x;
    int y;
    int dist;
};

void readMap(Map& map, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 't') ++treasures;
        }
    }
}

int bfs(Map& map, int x, int y) {
    int max_distance = -1;
    // four directions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    // cell position (x, y) and distance from source
    // initial pos with distance 0 into q
    queue<Cell> q;
    q.push({x, y, 0});

    while (not q.empty()) {
        Cell cell = q.front();
        q.pop();
        if (map[cell.x][cell.y] == 'X') continue;
        if (map[cell.x][cell.y] == 't' and cell.dist > max_distance) max_distance = cell.dist;
        map[cell.x][cell.y] = 'X';
        // check four directions
        for (int i = 0; i < 4; ++i) {
            int new_x = cell.x + dx[i];
            int new_y = cell.y + dy[i];
            if (new_x >= 0 and new_x < map.size() and new_y >= 0 and new_y < map[0].size()) {
                q.push({new_x, new_y, cell.dist + 1});
            }
        }
    }
    return max_distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    Map map(n, vector<char>(m));
    readMap(map, n, m);

    int x, y;
    cin >> x >> y;

    if (treasures != 0) {
        int max = bfs(map, x-1, y-1);
        if (max == -1) cout << "no treasure can be reached" << endl;
        else cout << "maximum distance: " << max << endl;
    }
    else cout << "no treasure can be reached" << endl;
}