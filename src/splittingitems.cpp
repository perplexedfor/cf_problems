#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    int res = 0;
    for(int i = 0;i < n;i++){
        if(i%2 == 0){
            res += v[i];
        }else{
            int needed = min(k,v[i-1]-v[i]);
            res -= v[i] + needed;
            k -= needed;
        }
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