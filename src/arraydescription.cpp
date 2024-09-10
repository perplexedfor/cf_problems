#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

void dfs(vector<int>v,int i,int m,long long& count,vector<long long>&dp){
    int n = v.size();
    if(i == n) count++;
    if(v[i] == 0){
        if(i > 0){
            if(i+1 != n){
                if(v[i+1] == 0){
                    v[i] = v[i-1];
                    dfs(v,i+1,m,count,dp);
                    if(v[i-1] != m){
                        v[i] = v[i-1] + 1;
                        dfs(v,i+1,m,count,dp);
                    }
                }else{
                    if(abs(v[i+1] - v[i-1]) > 2){
                        return;
                    }else{
                        v[i] = v[i-1];
                        dfs(v,i+1,m,count,dp);
                        v[i] = v[i-1] + 1;
                        dfs(v,i+1,m,count,dp);
                        v[i] = v[i+1];
                        dfs(v,i+1,m,count,dp);
                    }
                }
            }else{
                    v[i] = v[i-1];
                    dfs(v,i+1,m,count,dp);
                    if(v[i-1] != m){
                        v[i] = v[i-1] + 1;
                        dfs(v,i+1,m,count,dp);
                    }
                }
            }else{
                if(i+1 != n){
                    if(v[i+1] == 0){
                        for(int k = 1;k <= m;k++){
                            v[i] = k;
                            dfs(v,i+1,m,count,dp);
                        }
                    }else{
                        v[i] = v[i+1];
                        dfs(v,i+1,m,count,dp);
                        v[i] = v[i+1]-1;
                        dfs(v,i+1,m,count,dp);
                    }
                }else{
                    count += n;
                }
            }
    }else{
        dfs(v,i+1,m,count,dp);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    long long count = 0;
    vector<long long> dp(n,-1);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    dfs(v,0,m,count,dp);
    int val = count % mod;
    cout << val;
}