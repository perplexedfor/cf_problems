#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> a(n);
        for(auto &x : a){
            cin >> x.first;
        }
        for(auto &x : a){
            cin >> x.second;
        }
        sort(a.begin(),a.end());

        long long ans = 0;
        //case 1 maximize one element which can be changed
        for(int i = 0;i < n;i++)if(a[i].second == 1){
            int mc;
            if(i < n/2) mc = a[n/2].first;
            else mc = a[(n-2)/2].first;

            ans = max(ans,0LL + a[i].first + k + mc);
        }
        //case 2 maximize the median of n-1 element and take the maximum n element
        int l0 = 0,hi = 2e9;
        while(l0 != hi){
            int mid = (1LL + l0 + hi)/2;
            int z = 0;
            vector<int> smaller_list;
            for(int i = 0;i < n - 1;i++){
                if(a[i].first >= mid){
                    z++;
                }else if(a[i].second == 1){
                    smaller_list.push_back(mid - a[i].first);
                }
            }
            reverse(smaller_list.begin(),smaller_list.end());
            int kk = k;
            for(auto x : smaller_list) if(kk >= x){
                kk -= x;
                z++;
            }
            if(z >= (n+1)/2) l0 = mid;
            else hi = mid - 1;
        }
        ans = max(ans,0LL + a[n-1].first + l0);
        cout << ans << '\n';
    }
}