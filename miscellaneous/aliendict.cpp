#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
    public:
        string findOrder(string dict[],int N,int K){
            vector<int> adj[K];
            for(int i = 0;i < N - 1;i++){
                string s1 = dict[i];
				string s2 = dict[i+1];
				int n = min(s1.size(),s2.size());
				for(int j = 0;j < n;j++){
					if(s1[j] != s2[j]){
						adj[s1[j]-'a'].push_back(s2[j]-'a');
						break;
					}
				}
            }
			vector<int> res = topoSort(K,adj);
			
        }
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}