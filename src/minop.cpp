#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // If n is smaller than m, the answer is just m.
    if (k == 1) {
        cout << n << '\n';
        return;
    }

    int ans = 0;  // To store the number of steps
    
    while(n){
        ans += n%k;
        cout << ans << '\n';
        n /= k;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}