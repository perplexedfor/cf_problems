#include <bits/stdc++.h>
using namespace std;

int gcd(int n,int m){
    if(m == 0) return n;
    int val = n%m;
    return gcd(m,val);
}

long long range_sum(int l,int r){
    return (long long)(l+r)*(r-l+1)/2;
}

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    int val;
    val = x > y ? gcd(x,y) : gcd(y,x);

    long long lcm = (long long)(((long long)x*(long long)y)/val);

    int plus = n/x - n/lcm;
    int minus = n/y - n/lcm;

    cout << range_sum(n-plus+1,n) - range_sum(1,minus) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

