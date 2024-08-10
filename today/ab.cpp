#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n = n/10;
    }
    cout << sum << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}