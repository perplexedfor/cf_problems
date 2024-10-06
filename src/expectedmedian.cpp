#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
const int maxnCr = 2e6+5;
const int mod = 1e9 + 7;
int nCr(int cnt,int r){

}
void solve(){
    int n,k;
    cin >> n >> k;
    int sum = 0;
    int oddCnt = 0;
    int evenCnt = 0;
    for(int i = 0;i < n;i++){
        int val;
        cin >> val;
        if(val == 1){
            oddCnt++;
        }else{
            evenCnt++;
        }
    }
    int ans = 0;
    for(int i = k/2 + 1;i <= min(oddCnt,k);i++){
        sum += nCr(oddCnt,i)*nCr(evenCnt,k-i)%mod;
        sum %= mod;
    }
    cout << sum << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}