#include <bits/stdc++.h>
using namespace std;

int main(){
    int v; 
    cin >> v;
    

    vector<vector<pair<int,int>>> a(v); 
    

    vector<int> weight(v, INT_MAX);
    
    for(int i = 0; i < v; i++){
        int n; 
        cin >> n;
        
        vector<pair<int,int>> connected(n);
        for(int j = 0; j < n; j++){
            cin >> connected[j].first >> connected[j].second;
        }
        a[i] = connected;
    }

    int start;
    cin >> start;
    if(start >= v || start < 0){
        cout << "Invalid start node";
        return 0;
    }
    
    int end;
    cin >> end;
    if(end >= v || end < 0){
        cout << "Invalid end node";
        return 0;
    }
    

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    

    pq.push({0, start});
    weight[start] = 0;
    

    while(!pq.empty()){
        int wt = pq.top().first; 
        int node = pq.top().second; 
        pq.pop();
        

        for(int i = 0; i < a[node].size(); i++){
            int adjNode = a[node][i].first; 
            int adjWt = a[node][i].second;   
            

            if(wt + adjWt < weight[adjNode]){
                weight[adjNode] = wt + adjWt;
                pq.push({weight[adjNode], adjNode});
            }
        }
    }
    
    // Output the result
    if(weight[end] == INT_MAX) 
        cout << "Not Possible";
    else 
        cout << "The minimum weight to reach the destination is " << weight[end];
    
    return 0;
}
