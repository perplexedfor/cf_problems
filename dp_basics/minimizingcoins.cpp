#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    vector<int> dp(s+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1;i <= s;i++){
        for(int j = 0;j < n;j++){
            if(i - v[j] >= 0 && dp[i-v[j]] != INT_MAX){
                dp[i] = min(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    if(dp[s] == INT_MAX){
        cout << -1;
        return 0;
    } 
    cout << dp[s];
}