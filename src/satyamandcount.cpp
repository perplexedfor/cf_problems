#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> s;
    unordered_map<int,set<int>> mpp;
    for(int i = 0;i < n;i++){
        int n,m;
        cin >> n >> m;
        s.insert(n);
        mpp[n].insert(m);
    }
    int res = 0;
    for(auto &it : mpp){
        if(it.second.size() == 2){
            res += n-2;
        }
    }
    vector<int> v(s.begin(),s.end());
    for(int i = 0;i < v.size()-2;i++){
        int prev = v[i];
        int take = true;
        for(int j = 1;j < 3;j++){
            if(v[i+j] != prev+1 && (mpp[v[i+j]].find(j%2) == mpp[v[i+j]].end())){
                take = false;
                break;
            }
            prev = v[i+j];
        }
        if(take){
            cout << "k" << '\n';
            res++;
        }
    }
    cout << res << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}