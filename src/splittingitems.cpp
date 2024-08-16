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
    int maxVal = v[0];
    int i = n - 1;
    while(k != 0){
        if(i < 0) break;
        if(k > maxVal - v[i]){
            // cout << v[i];
            k -= maxVal - v[i];
            // cout << k;
            v[i] = maxVal;
            i--;
        }else{
            v[i] += k;
            k = 0;  
        }
    }
    sort(v.rbegin(),v.rend());
    int res = 0;
    for(int i = 0;i < n;i++){

        if(i%2 == 0){
            res += v[i];
        }else{
            res -= v[i];
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