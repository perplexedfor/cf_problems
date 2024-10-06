#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> order(n);
    for(int i = 0;i < n;i++){
        cin >> order[i];
    }
    set<int> occupied;
    occupied.insert(order[0]);
    for(int i = 1;i <= n;i++){
        int val = order[i];
        int prev = val-1;
        if((occupied.find(prev) == occupied.end()) && occupied.find(val+1) == occupied.end()){
            cout << "NO" << '\n';
            return;
        }else{
            occupied.insert(val);
        }
    }
    cout << "YES" << '\n';

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}