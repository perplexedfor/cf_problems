#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long mod = 1e9 + 7;
    vector<long long> v(n+1);
    v[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = i - 6;j < i;j++){
            if(j >= 0){
                v[i] = (v[i]+v[j])%mod;
            }
        }
    }
    cout << v[n];
}