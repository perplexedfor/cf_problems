#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
int mod = 1e9 + 7;

// int dfs(vector<int>&coins,int t,int i){
//     if(t == 0){
//         return 1;
//     }
//     if(t < 0 || i >= coins.size()){
//         return 0;
//     }
//     if(memo[t][i] != -1){
//         return memo[t][i];
//     }
//     int ways = 0;
//     ways = (ways + dfs(coins,t - coins[i],i))%mod;
    
//     ways = (ways + dfs(coins,t,i+1))%mod;
//     return memo[t][i] = ways;
// }
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    memo = vector<vector<int>>(n+1,vector<int>(x+1,0));
    
    for(int i = 0;i <= n;i++){
        memo[i][0] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= x;j++){
            memo[i][j] = memo[i-1][j];
            if(j >= coins[i-1]){
                memo[i][j] = (memo[i][j] + memo[i][j-coins[i-1]])%mod;
            }
        }
    }
    cout << memo[n][x] <<'\n';
    
}