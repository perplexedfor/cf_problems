//output shall be number of operations and then the operation array
#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e5 + 5;
int n,a[max_n];
void solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    bool is_even,is_odd;
    for(int i = 1;i <= n;i++){
        if(a[i]%2 == 0){
            is_even = true;
        }else{
            is_odd = false;
        }
    }
    if(is_even && is_odd){
        cout << -1 << '\n';
        cout << '\n';
    }else{
        vector<int> operations;
        for(int i = 29;i >= 0;i++){
            operations.push_back(1 << i);
        }
        if(is_even){
            operations.push_back(1);
        }
        cout << operations.size() << '\n';
        for(int x : operations)
            cout << x << ' ';
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