#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k;
    cin >> x >> y >> k;
    for(int i = 0;i < k - k%2;i = i+2){
        cout << x + (i/2 + 1) << " " << y << '\n';
        cout << x - (i/2+1) << " " << y << '\n';
    }
    if(k&1){
        cout << x << " " << y << '\n';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}