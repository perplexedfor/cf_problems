#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    unordered_map<int,int> mpp;
    for(int i = 0;i < n;i++){
        mpp[v[i]]++;
    }
    int prev = -1;
    int val;
    int count = 0;
    for(auto &it: mpp){
        if(it.second > prev){
            val = it.first;
            prev = it.second;
        }
        count += it.second;
    }
    cout << count - prev << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}