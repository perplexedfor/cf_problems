#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin >> k;
    long long l = 1, r= 2e18;
    while(l < r){
        long long mid = (l+r) >> 1;
        long long n = mid - int(sqrtl(mid));
        if(n >= k) r = mid;
        else l = mid+1;
    }
    cout << r << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}