#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n,-1);
    if(n%2 == 0){
        cout << -1 << '\n';
    }else{
        vector<int> v(n);
        int i = 0;
        int j = n-1;
        int ins = 1;
        while(i < j){
            v[i] = ins;
            ins++;
            i++;
            v[j] = ins;
            ins++;
            j--;
        }
        if(n%2 != 0) v[i] = ins;
        for(auto&it:v){
            cout << it << ' ';
        }
        cout << '\n';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}