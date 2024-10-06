#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;
int n,b[max_n],a[max_n];
void solve(){
    cin >> n;
    for(int i = 1;i < n;i++){
        cin >> b[i];
    }
    b[0] = b[n] = 0;
    for(int i = 1;i <= n;i++){
        a[i] = b[i] | b[i-1];
    }
    bool valid = true;
    for(int i = 1;i < n;i++){
        if((a[i] & a[i+1]) != b[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        for(int i = 1;i <= n;i++){
            cout << a[i] << " ";
        }
        cout << '\n';
    }else{
        cout << -1 << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}