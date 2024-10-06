#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        lli cur = 0;
        lli n = s.size();
        lli ans = 0;
        map<lli,lli> prevSumValIndx;
        const lli mod = 1000000000+7;
        for(lli i = 0;i < n;i++){
            cur += s[i] == '0' ? -1 : 1;
            ans += (n-i)*(prevSumValIndx[cur]%mod);
            prevSumValIndx[cur] += i+2;
        }
        ans %= mod;
        cout << ans << endl;
        return 0;
    }

}