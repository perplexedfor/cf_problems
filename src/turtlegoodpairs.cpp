#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int,int>> v(26);
    for(int i = 0;i < 26;i++){
        v[i] = {0,i};
    }
    for(int i = 0;i < n;i++){
        ++v[s[i]-'a'].first;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    queue<pair<int,int>> q;
    while(v[0].first > v[1].first){
        putchar('a' + v[0].second);
        --v[0].first;
    }
    for(int i = 0;i < 26;i++){
        q.push(v[i]);
    }
    while(q.size()){
        pair<int,int> p = q.front();
        q.pop();
        if(!p.first) continue;
        putchar('a'+p.second);
        --p.first;
        q.push(p);
    }
    putchar('\n');
    // unordered_map<char,int> mpp;
    // for(int i = 0;i < n;i++){
    //     mpp[s[i]]++;
    // }
    // vector<char> res(n,' ');
    // int i = 0;
    // int j = i;
    // for(auto &it: mpp){
    //     char ch = it.first;
    //     int val = it.second;
    //     while(val--){
    //         res[j] = ch;
    //         j = j+2;
    //         if(j >= n){
    //             j = i+1;
    //         }
    //     }
    // }
    // string o = "";
    // for(auto &it:res){
    //     o += it;
    // }
    // cout << o << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}