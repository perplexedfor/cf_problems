#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long> res;
    while(n--){
        int sum = 0;
        priority_queue<pair<int,int>>pq;
        int s,k;
        cin >> s >> k;
        vector<int> a(s);
        vector<int> b(s);
        for(int i = 0;i < s;i++){
            cin >> a[i];
        }
        for(int j = 0;j < s;j++){
            cin >> b[j];
        }
        for(int i = 0;i < s;i++){
            pq.push({a[i],b[i]});
        }
        while(k-- && !pq.empty()){
            int val = pq.top().first;
            int diff = pq.top().second;
            pq.pop();
            sum += val;
            if(val - diff > 0){
                pq.push({val-diff,diff});
            }
        }
        res.push_back(sum);
        // res.push_back(k);
    }
    for(auto& it: res){
        cout << it << '\n';
    }
    return 0;
}