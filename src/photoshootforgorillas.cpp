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

    // Initialize the matrix with zeros
    
    // Use a max-heap (priority queue) to store the matrix values in descending order
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l1 = max(0,i-k+1);
            int m1 = max(0,j-k+1);
            int l2 = min(i,n-k);
            int m2 = min(j,m-k);
            pq.push((m2-m1+1)*(l2-l1+1));
        }
    }

    // Sort weights in descending order
    sort(wt.begin(), wt.end(), greater<int>());

    long long res = 0;
    // Calculate result by multiplying the highest values from the matrix with the weights
    for (int i = 0; i < w; i++) {
        if (!pq.empty()) {
            int cnt = pq.top();
            pq.pop();
            res += cnt * wt[i];
        }
    }
    return;
    // cout << res << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}