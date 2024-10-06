#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> res;
    function<void(int, int, int, int)> towerOfHanoi = [&](int n, int from, int to,int aux){
        if(n == 1){
            res.push_back({from,to});
            return;
        }
        towerOfHanoi(n-1,from,aux,to);
        res.push_back({from,to});
        towerOfHanoi(n-1,aux,to,from);
    };
    towerOfHanoi(n, 1, 3, 2);
    cout << res.size() << '\n';
    for(auto &it: res){
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}