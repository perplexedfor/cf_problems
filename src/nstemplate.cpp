#include <bits/stdc++.h>
using namespace std;

void connect(vector<int>&match){
    string s;
    cin >> s;
    unordered_map<char,int> mpp;
    if(s.size() != match.size()){
        cout << "NO" << '\n';
        return;
    } 
    for(int i = 0;i < s.size();i++){
        if(mpp.find(s[i]) != mpp.end()){
            int val = mpp[s[i]];
            if(val != match[i]){
                cout << "NO" << '\n';
                return;
            }
        }else{
            mpp[s[i]] = match[i];
        }
    }
    cout << "YES" << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> match(n);
    for(int i = 0;i < n;i++){
        cin >> match[i];
    }
    int s;
    cin >> s;
    while(s--){
        connect(match);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}