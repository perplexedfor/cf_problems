#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<vector<int>>> res;

    while (n--) {
        int k, m;
        cin >> k >> m;
        vector<vector<int>> grid(k, vector<int>(k));

        // Read the grid
        for (int i = 0; i < k; i++) {
            string val;
            cin >> val;
            for (int j = 0; j < k; j++) {
                grid[i][j] = val[j] - '0';
            }
        }

        int size = k / m;
        vector<vector<int>> val(size, vector<int>(size));

        // Sample elements at intervals
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                val[i][j] = grid[i * m][j * m];
            }
        }

        res.push_back(val);
    }

    // Output the results
    for (const auto& it : res) {
        for (int i = 0; i < it.size(); i++) {
            for (int j = 0; j < it[i].size(); j++) {
                cout << it[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}

