#include <bits/stdc++.h>
using namespace std;
//take notes 
//the bitwise complement of a number with other number
// when xor xored and added with random number will give same result
void solve(){
    int l,r;
    cin >> l >> r;
    int k = 31 - __builtin_clz(l^r);
    int a = l | ((1 << k) - 1),b = a+1,c = (a == l ? r : l );
    cout << a << " " << b << " " << c << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}