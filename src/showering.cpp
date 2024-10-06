#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,m;
    cin >> n >> s >> m;
    int prev = 0;
    bool p = false;
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        if(l-prev >= s){
            p = true;
        }
        prev = r;
    }
    if(m-prev >= s){
        p = true;
    }
    if(p){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }
    
    
    // cout << maxLength << '\n';

    // if(maxLength >= s){
    //     cout << "YES" << '\n';
    // }else{
    //     cout << "NO" << '\n';
    // }

    // int sum = 0;
    // while(n != 0){
    //     sum += n%10;
    //     n = n/10;
    // }
    // cout << sum << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}