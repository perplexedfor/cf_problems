#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<pair<int,int>> v(2);
    cin >> v[0].first >> v[0].second;
    cin >> v[1].first >> v[1].second;
    sort(v.begin(),v.end());
    int l = v[0].first;
    int r = v[0].second;
    int L = v[1].first;
    int R = v[1].second;
    if(r < L){
        cout << 1 << '\n';
        return;
    }
    int k = max(l,L);
    int m = min(r,R);
    int res = 0;
    res += m-k;
    if(k > l){
        res++;
    }
    if(m < max(r,R)){
        res++;
    }
    cout << res << '\n';

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
