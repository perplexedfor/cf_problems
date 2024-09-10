#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    unordered_map<int,int> mpp;
    for(int i = 0;i < n;i++){
        cin >> p[i].first >> p[i].second;
        mpp[p[i].second]++;
    }
    sort(p.begin(),p.end());
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}