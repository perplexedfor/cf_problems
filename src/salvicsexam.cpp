#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int i = 0,j = 0;
    while(i < s.size() && j < t.size()){
        if(s[i] == '?'){
            s[i] = t[j];
            j++;
        }else if(s[i] == t[j]){
            j++;
        }
        i++;
    }
    if(j < t.size()){
        cout << "NO" << '\n';
    }else{
        i = 0;
        while(i < s.size()){
            if(s[i] == '?'){
                s[i] = 'a';
            }
            i++;
        }
        cout << "YES" << '\n';
        cout << s << '\n';
    }
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}