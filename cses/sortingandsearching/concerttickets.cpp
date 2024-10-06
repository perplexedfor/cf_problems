#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    multiset<int> Tick;
    while(n--){
        int k;
        cin >> k;
        Tick.insert(k);
    }
    while(m--){
        int x;
        cin >> x;
        auto it = Tick.upper_bound(x);
        int ans = -1;
        if(it != Tick.begin()){
            --it;
            ans = *it;
            Tick.erase(it);
        }
        cout << ans << '\n';
    }

    // Output the result
    // for(auto &it : res){
    //     cout << it << '\n';
    // }
}
    // vector<int> tickP(n);
    // for(int i = 0; i < n; i++){
    //     cin >> tickP[i];
    // }
    // sort(tickP.begin(), tickP.end());

    // vector<int> custP(m);
    // for(int i = 0; i < m; i++){
    //     cin >> custP[i];
    // }

    // // Value and maxIndex
    // unordered_map<int, int> count;
    // unordered_map<int, int> prev;

    // for(int i = 0; i < n; i++){
    //     if(i == 0){  // Fixed the typo
    //         prev[tickP[i]] = -1;
    //     } else {
    //         prev[tickP[i]] = tickP[i-1];
    //     }
    //     count[tickP[i]]++;
    // }

    // vector<int> res;
    // for(int i = 0; i < m; i++){
    //     int val = custP[i];
    //     auto it = upper_bound(tickP.begin(),tickP.end(),val);
    //     if(*(it-1)){
    //         val = *(it-1);
    //     }
    //     cout << val << '\n';
    //     while(val != -1 && count[val] == 0){
    //         val = prev[val];
    //     }
    //     if(val != -1){
    //         count[val]--; // Ticket sold, reduce the count
    //     }
    //     res.push_back(val); // Add result, can be -1 if no ticket found
    // }

    // vector<pair<int,int>> custP(m);
    // for(int i = 0;i < m;i++){
    //     cin >> custP[i].first;
    //     custP[i].second = i;
    // }
    // sort(custP.begin(),custP.end());

    // vector<int> lastTaken = {-1};
    // vector<pair<int,int>> resP;
    // for(auto &it : custP){
    //     int ind = lastTaken.back()+1;
    //     int temp = ind;
    //     while(tickP[ind] <= it.first){
    //         ind++;
    //     }
    //     ind = ind - 1;
    //     if(temp == ind){
    //         int i = lastTaken.size()-1;
    //         ind--;
    //         while(i >= 0 && lastTaken[i] == ind){
    //             i--;
    //             ind--;
    //         }
    //         if(i < 0){
    //             resP.push_back({it.second,-1});
    //         }else{
    //             lastTaken.push_back(ind);
    //             sort(lastTaken.begin(),lastTaken.end());
    //             resP.push_back({it.second,tickP[ind]});
    //         }
    //     }else{
    //         lastTaken.push_back(ind);
    //         resP.push_back({it.second,tickP[ind]});
    //     }
    // }
    // sort(resP.begin(),resP.end());
    // for(auto &it : resP){
    //     cout << it.second << '\n';
    // }