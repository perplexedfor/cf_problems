#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<vector<int>> dp(1e5 + 5,vector<int>(103));

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    for(int j = 1;j < m;j++){
        dp[1][j] = (v[1] == 0 || v[1] == j);
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(v[i] != 0){
                if(v[i] != j){
                    dp[i][j] = 0;
                    continue;
                }
            }
            dp[i][j] = 0;
            for(int k = -1;k <= 1;k++){
                if(k+j < 1 || k+j > m) continue;
                dp[i][j] = (dp[i-1][k+j]+dp[i][j])%mod;
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= m;i++){
        ans = (ans + dp[n][i])%mod;
    }
    cout << ans;
}