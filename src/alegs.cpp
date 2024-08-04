#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> check;
    while(n--){
        int k;
        cin >> k;
        check.push_back(k);
    }
    for(auto& it: check){
        int res = it/4;
        it = it%4;
        res += it/2;
        cout << res << '\n';
    }
    return 0;
}