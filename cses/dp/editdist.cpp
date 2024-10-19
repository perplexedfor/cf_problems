#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    a = '*' + a;
    b = '*' + b;
    int n = a.size();
    int m = b.size();
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            dp[i][j] = max(i,j);
            if(i == 0 || j == 0) continue;
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            dp[i][j] = min(dp[i][j],1 + dp[i-1][j]);
            dp[i][j] = min(dp[i][j],1+dp[i][j-1]);
            dp[i][j] = min(dp[i][j],1 + dp[i-1][j-1]);
        }
    }
    cout << dp[n][m];
    return 0;
}