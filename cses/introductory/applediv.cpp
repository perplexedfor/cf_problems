#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    long sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    long res = INT_MAX;
    function<void(int,long)> findAll =  [&](int ind,long curr){
        if(ind == n){
            res = min(res,abs(sum-2*curr));
            return;
        }
        findAll(ind+1,curr + a[ind]);
        findAll(ind+1,curr);
    };
    findAll(0,0);
    cout << res;
}