
#include <bits/stdc++.h>

using namespace std;

vector<long> dfs(vector<int>& time, long sum1, long sum2, bool turn, int i,
                 vector<vector<vector<long>>>& dp) {
    int n = time.size();
    if (i == n) {
        vector<long> res = {sum1, sum2};
        return res;
    }
    if (!dp[i][turn].empty()) {
        return dp[i][turn];
    }
    vector<long> p, temp;
    if (turn) {
        p = dfs(time, sum1 + time[i], sum2, !turn, i + 1, dp);
        temp = dfs(time, sum1, sum2 + time[i], turn, i + 1, dp);
        if (abs(temp[0] - temp[1]) < abs(p[0] - p[1])) {
            p = temp;
        }
    } else {
        p = dfs(time, sum1 , sum2 + time[i], !turn, i + 1, dp);
        temp = dfs(time, sum1 + time[i], sum2 , turn, i + 1, dp);
        if (abs(temp[0] - temp[1]) < abs(p[0] - p[1])) {
            p = temp;
        }
    }
    dp[i][turn] = p;
    return p;
}

int main() {
    vector<int> time = {1, 2, 3, 4, 5}; // Example input
    int n = time.size();
    vector<vector<vector<long>>> dp(n, vector<vector<long>>(2));
    
    vector<long> pairs = dfs(time, 0, 0, true, 0, dp);
    
    cout << "Optimal partition: " << pairs[0] << " " << pairs[1] << endl;
    return 0;
}