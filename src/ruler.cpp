#include <bits/stdc++.h>
using namespace std;

int query(int u,int v){
    cout << "? " << u << ' ' << v << '\n';
    cout.flush();
    int x;cin >> x;
    return x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l = 2;
        int r = 1000;
        int res = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            int val = query(1,mid);
            if(val == mid){
                l = mid+1;
            }else{
                res = mid;
                r = mid-1;
            }
        }
        cout << "! " << res << '\n';
    }
}
