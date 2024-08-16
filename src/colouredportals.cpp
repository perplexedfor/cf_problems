
#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, int start, int end) {
    int n = adj.size();
    vector<int> dist(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        if (weight > dist[node]) continue;
        
        for (auto& it : adj[node]) {
            int neigh = it.first;
            int adjW = it.second;
            if (weight + adjW < dist[neigh]) {
                dist[neigh] = weight + adjW;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    
    if (dist[end] == 1e9) cout << -1 << endl;
    else cout << dist[end] << endl;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; 
        queries[i].second--;
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i][0] == v[j][0] || v[i][1] == v[j][0] || v[i][1] == v[j][1] || v[i][0] == v[j][1]) {
                adj[i].push_back({j, j - i});
                adj[j].push_back({i, j - i});
            }
        }
    }
    for (int i = 0; i < q; i++) {
        dijkstra(adj, queries[i].first, queries[i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;    
    while (t--) {
        solve();
    }
    return 0;
}
