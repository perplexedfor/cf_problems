#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;

    vector<pair<int,int>> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());

    pair<int,int> res {0,0};
    for(int i = 0;i < n;i++){
        int l = i + 1;
        int r = n - 1;
        int find = x - v[i].first;

        if(find < v[i].first){
            break;
        }
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid].first < find){
                l = mid + 1;
            }else if(v[mid].first > find){
                r = mid - 1;
            }else{
                res.first = v[i].second;
                res.second = v[mid].second;
                break;
            }
        }
       
    }
    if(res.first == 0 && res.second == 0){
        cout << "IMPOSSIBLE";
    }else{
        if(res.first > res.second){
            swap(res.first,res.second);
        }
        cout << res.first+1 << " " << res.second+1;
    }
}