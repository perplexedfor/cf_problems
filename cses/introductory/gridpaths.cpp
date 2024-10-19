#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int totalMoves = 48;
    int n = 7, m = 7;
    map<char, int> mp = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}, {'?', -1}};
    vector<int> moveOrder(s.size());

    for (int i = 0; i < s.size(); i++) {
        moveOrder[i] = mp[s[i]];
    }

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    vector<vector<bool>> v(n + 2, vector<bool>(m + 2, true));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = false;
        }
    }
    v[1][1] = true;
    int totalPaths = 0;

    auto numComponents = [&](int x, int y) {
        auto isValid = [&](int x, int y) -> bool {
            if (v[x][y]) return false;
            return true;
        };
        if (isValid(x, y - 1) && isValid(x, y + 1) && !isValid(x - 1, y) && !isValid(x + 1, y)) return false;
        if (isValid(x - 1, y) && isValid(x + 1, y) && !isValid(x, y - 1) && !isValid(x, y + 1)) return false;
        return true;
    };

    auto tryAll = [&](auto self, int x, int y, int moveInd) -> void {
        if (!numComponents(x, y)) {
            return;
        }
        if (x == n && y == 1) {
            if (moveInd == totalMoves) {
                totalPaths++;
            }
            return;
        }        

        if (moveOrder[moveInd] != -1) {
            int nx = x + dx[moveOrder[moveInd]], ny = y + dy[moveOrder[moveInd]];
            if (v[nx][ny]) {
                return;
            }
            v[nx][ny] = true;
            self(self, nx, ny, moveInd + 1);
            v[nx][ny] = false;
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (v[nx][ny]) continue;
                v[nx][ny] = true;
                self(self, nx, ny, moveInd + 1);
                v[nx][ny] = false;
            }
        }
    };

    tryAll(tryAll, 1, 1, 0);
    cout << totalPaths << "\n";
}