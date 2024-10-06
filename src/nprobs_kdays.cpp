#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    if(n*(n-1)/2 > k){
        cout << "NO";
    }else {
        vector<int> ans(k,1);
        n -= k*(k-1)/2;
        for(int i = 0;i < k;i++){
            ans[i] += n/k;
        }
        n = n%k;
        for(int i = k - 1;i > 0 && ans[i-1] != 1 && n > 0;i--){
            ans[i]++;n--;
        }
        ans[k-1] += n;
        for (int i = 0; i < k - 1; i ++)
            if (ans[i] * 2 < ans[i + 1]) {
                cout << "NO";
                return 0;
            }
        
        cout << "YES\n";
        for (auto &x: ans) cout << x << ' ';
    }
    return 0;
}