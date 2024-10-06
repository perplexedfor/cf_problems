#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Change the order to prioritize L, D, R, U
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const char dir[] = {'L', 'D', 'R', 'U'};

bool bfs(vector<vector<char>>& labyrinth, int start_x, int start_y, int end_x, int end_y, string& path) {
    int n = labyrinth.size(), m = labyrinth[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == end_x && y == end_y) {
            // Reconstruct path
            while (x != start_x || y != start_y) {
                int px = parent[x][y].first, py = parent[x][y].second;
                for (int i = 0; i < 4; i++) {
                    if (px + dx[i] == x && py + dy[i] == y) {
                        path = dir[i] + path;
                        break;
                    }
                }
                x = px; y = py;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && labyrinth[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    int start_x, start_y, end_x, end_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                start_x = i; start_y = j;
            } else if (labyrinth[i][j] == 'B') {
                end_x = i; end_y = j;
            }
        }
    }

    string path;
    bool found = bfs(labyrinth, start_x, start_y, end_x, end_y, path);

    if (found) {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}