#include <bits/stdc++.h>
using namespace std;

int query(int u,int v){
    cout << "? " << u << ' ' << v << '\n';
    int x;cin >> x;
    return x;
}
void ans(int u,int v,vector<bool>&visited,vector<int>&parent){
    int x = query(u,v);
    if(x == u){
        parent[v] = u;
        visited[v] = true;
        return;
    }
    ans(x,v,visited,parent);
}
void solve(){
    int n;
    cin >> n;
    vector<int> parent(n+1);
    vector<bool> visited(n+1,false);
    visited[1] = true;
    for(int i = 2;i <= n;i++){
        ans(1,i,visited,parent);
    }
    cout << "! ";
    for(int i = 2;i <= n;i++) cout << i << " " << parent[i] << " ";
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}