#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // at each step subtract one of the digit from the number and return the number of steps req
    vector<string> grid(n);
    for(int i = 0;i < n;i++){
        cin >> grid[i];
    }
    int mod = 1e9+7;
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = 1;
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    } 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(grid[i][j] == '*') continue;
            if(i-1 >= 0){
                dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            }
            if(j-1 >= 0){
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    cout << dp[n-1][n-1];
}