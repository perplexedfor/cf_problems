#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxCorrect = 0;
    vector<int> v(4,0);
    for(int i = 0;i < s.size();i++){
        if(s[i] == '?'){
            continue;
        }
        if(v[s[i]-'A'] < n){
            maxCorrect++;
            v[s[i]-'A']++;
        }
    }
    cout << maxCorrect << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}