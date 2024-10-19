#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i < n;i++){
        int n,m;
        cin >> n >> m;
        v[i] = {m-1,n};
    }
    int taken = 0;
    int res = 0;
    sort(v.begin(),v.end());
    for(int i = 0;i < v.size();i++){
        if(v[i].second > taken){
            taken = max(taken,v[i].first);
            res++;
        }
    }
    cout << res; 

}