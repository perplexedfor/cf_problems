#include <bits/stdc++.h>
using namespace std;

#define int ll

using ll = long long;


const int N = 2e5 + 20,inf = 2e15 + 20;
int n, a[N];
vector<int> g[N];

bool dfs(int v,int val){
    if(g[v].empty() && a[v] < val) return false;
    if(!v) val = max(0ll,val - a[v]);
    else if(a[v] < val) val = min(inf,val+val - a[v]);

    for(int u : g[v]){
        if(!dfs(u,val)) return false;
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        int par;
        cin >> par;
        g[par-1].push_back(i); 
    }
    int l = 0, h = inf;

    while(h - l > 1){
        int mid = (l + h)/2;
        if(dfs(0,mid)) l = mid;
        else h = mid;
    }
    // while(l <= r){
    //     int mid = (l+r)/2;
    //     if(dfs(0,mid,graph)){
    //         l = mid + 1;
    //     }else{
    //         r = mid - 1;
    //     }
    // }
    cout << l << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}