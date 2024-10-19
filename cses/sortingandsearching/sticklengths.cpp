#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    long long int pre = 0;
    long long int suff = accumulate(v.begin(),v.end(),0ll);
    long long int sum = suff;

    for(int i = 0;i < n;i++){
        suff -= v[i];
        sum = min(sum,i*v[i] - pre + suff - v[i]*(n-i-1));
        pre += v[i];
    }
    cout << sum;


}