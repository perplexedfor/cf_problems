#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        // Correctly initialize map
        unordered_map<int,int> a;
        
        // Input values and count frequencies
        for(int i = 0; i < n; i++) {
            int v;
            cin >> v;
            a[v]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // {count, value}
        for(auto &it : a) {

            // if(it.second <= k) {

                pq.push({it.second, it.first});

            // }
        }
        int remaining_k = k;
        //this approach gave tle this is bad as priority queue has logn time complexity for pop operation
        while(!pq.empty() && remaining_k >= pq.top().first) {
            auto it = pq.top();
            pq.pop();
            remaining_k -= it.first;
            // a.erase(it.second);
        }
        
        int ans = pq.size();
        cout << (ans == 0 ? 1 : ans) << "\n";
    }
    return 0;
}

// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> a[i];
//     }
//     std::sort(a.begin(), a.end());
//     std::vector<int> cnt = {1};
//     for (int i = 1; i < n; i++) {
//         if (a[i] == a[i - 1]) {
//             cnt.back()++;
//         } else {
//             cnt.emplace_back(1);
//         }
//     }
//     std::sort(cnt.begin(), cnt.end());
//     int m = cnt.size();
//     for (int i = 0; i < m - 1; i++) {
//         if (cnt[i] > k) {
//             std::cout << m - i << "\n";
//             return;
//         }
//         k -= cnt[i];
//     }
//     std::cout << 1 << "\n";
// }

// signed main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int t = 1;
//     std::cin >> t;

//     while (t--) {
//         solve();
//     }
// }