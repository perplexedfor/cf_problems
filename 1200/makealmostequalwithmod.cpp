#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    for(int bit = 0; bit <= 60; bit++) {  // Since numbers are ≤ 10^17
        ll mask = 1LL << bit;
        set<ll> patterns;
        
        // Get the pattern for each number up to this bit
        for(int i = 0; i < n; i++) {
            patterns.insert(a[i] & ((1LL << (bit + 1)) - 1));  
        }
        
        if(patterns.size() == 2) {
            ll k = 1LL << (bit + 1);
            cout << k << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}