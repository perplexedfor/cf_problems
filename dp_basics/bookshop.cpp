#include <bits/stdc++.h>
using namespace std;
// int res = INT_MIN;
// void dfs(vector<int>&price,vector<int>&pages,int i,int count,int x){
//     if(x == 0 || i == pages.size()){
//         res = max(res,count);
//         return;
//     } 
//     if(x - price[i] >= 0){
//         dfs(price,pages,i+1,count+pages[i],x-price[i]);
//     }
//     dfs(price,pages,i+1,count,x);
// }
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0;i < n;i++){
        cin >> price[i];
    }
    for(int i = 0;i < n;i++){
        cin >> pages[i];
    }
    // dfs(price,pages,0,0,x);
    //standard knapsack problem
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= x;j++){
            if(j >= price[i-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j - price[i-1]] + pages[i-1]);
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    
    }
    cout << dp[n][x] << '\n';
}