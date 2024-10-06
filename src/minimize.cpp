#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    int sum = 0;
    int mid = (m - n)/2;
    sum = mid - n + m - mid;
    cout << sum << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}