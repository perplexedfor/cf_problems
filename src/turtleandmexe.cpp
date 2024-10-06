#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n  >> m;
    int k = 0;
    vector<vector<int>> v;
    while(n--){
        int t;
        cin >> t;
        set<int> present;
        for(int i = 0;i < t;i++){
            int x;
            cin >> x;
            present.insert(x);
        }
        vector<int> b;
        int missing = 0;
        while(b.size() < 2){
            if(!present.count(missing)){
                b.push_back(missing);
            }
            missing++;
        }
        v.push_back({b[0],b[1]});
        k = max(k,b[1]);
    }
    int ans = 0;
    if(k < m){
        
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}