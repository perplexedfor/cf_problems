#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0;i < n;i++){
        int n,m;
        cin >> n >> m;
        v.push_back({n,1});
        v.push_back({m,-1});
    }
    sort(v.begin(),v.end());
    int curr = 0;
    int most = 0;
    for(auto &it:v){
        if(it.second == 1) curr++;
        else curr--;
        most = max(most,curr);
    }
    cout << most;
}