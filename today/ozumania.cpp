#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0;j < 4;j++){
            if(s[j] == '#'){
                res[i] = j+1;
            }
        }
    }
    for(int i = n-1;i >= 0;i--){
        cout << res[i] << " ";
    }
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}