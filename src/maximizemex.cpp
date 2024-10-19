#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int ans = INT_MAX;

        unordered_map<int,int> mpp;

        for(int i = 0;i < n;i++){
            int k;
            cin >> k;
            mpp[k]++;
        }
        for(int i = 0;i < n;i++){
            if(!mpp.count(i)){
                ans = i;
                break;
            }
            if(i+x > n) continue;
            if(mpp[i] > 1){
                mpp[i+x] += mpp[i]-1;
                mpp[i] = 1;
            }
        }
        ans = ans == INT_MAX ? n : ans;
        cout << ans << '\n';

    }
}