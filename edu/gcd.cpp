#include <bits/stdc++.h>
using namespace std;
int gcd(int n,int m){
    if(m == 0) return n;
    int val = n%m;
    return gcd(m,val);
}
int main(){
    int n,m;
    cin >> n >> m;
    int val;
    if(n > m){
        val = gcd(n,m);
    }else{
        val = gcd(m,n);
    }
    cout << val;
}