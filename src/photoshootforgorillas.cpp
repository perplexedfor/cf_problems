#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> wt(w);
    for (int i = 0; i < w; i++) {
        cin >> wt[i];
    }
    //weights
    priority_queue<long long> pq;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int l1 = max(0,i-k+1);
            int m1 = max(0,j-k+1);
            int l2 = min(n-k,i);
            int m2 = min(m-k,j);
            pq.push((l2-l1+1)*(m2-m1+1));
        }
    }
    long long res = 0;
    sort(wt.begin(),wt.end(),greater<int>());
    for(int i = 0;i < w;i++){
        long long val = pq.top();
        pq.pop();
        res += wt[i]*val;
    }
    cout << res << '\n';

    // cout << res << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}