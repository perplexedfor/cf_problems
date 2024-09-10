#include <bits/stdc++.h>
using namespace std;

//brute force geometry greedy maths
long long dist(int x,int y,int a,int b){
    return 1ll*(x-a)*(x-a) + 1ll*(y-b)*(y-b);
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i].first >> v[i].second;
    }
    pair<int,int> start;
    cin >> start.first >> start.second;
    pair<int,int> end;
    cin >> end.first >> end.second;

    bool ok = true;

    for(int i = 0;i < n;i++){
        if(dist(v[i].first,v[i].second,end.first,end.second) <= dist(end.first,end.second,start.first,start.second)){
            ok = false;
            break;
        }
    }
     cout << (ok ? "YES\n" : "NO\n");
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}