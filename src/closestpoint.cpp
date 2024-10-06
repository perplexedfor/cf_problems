#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    if(n > 2){
        cout << "NO" << '\n';
        return;
    }
    if(abs(v[0] - v[1]) == 1){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

