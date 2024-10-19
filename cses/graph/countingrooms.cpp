#include <bits/stdc++.h>
using namespace std;

int counter = 0;  // This counts the number of connected components
vector<int> dirX = {-1, 0, 1, 0};
vector<int> dirY = {0, 1, 0, -1};

// DFS function to traverse connected components
void dfs(vector<string>& v, vector<vector<bool>>& visited, int r, int c) {
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dirY[i];
        int nc = c + dirX[i];
        if (nr >= 0 && nc >= 0 && nr < v.size() && nc < v[0].size() && !visited[nr][nc] && v[nr][nc] != '#') {
            dfs(v, visited, nr, nc);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Input rows and columns

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];  // Input the grid of strings
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));  // Visited array to track traversal

    // Iterate through each cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is not a wall and hasn't been visited, start a DFS
            if (v[i][j] != '#' && !visited[i][j]) {
                counter++;  // New connected component found
                dfs(v, visited, i, j);  // Perform DFS to mark the entire component
            }
        }
    }

    // Output the number of connected components
    cout << counter << endl;
}
