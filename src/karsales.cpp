#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;

        long long sum = 0;
        long long maxVal = 0;
        for(int i = 0;i < n;i++){
            long long v;
            cin >> v;
            maxVal = max(maxVal,v);
            sum += v;
        }    
        long long s = (sum-1)/x + 1;
        long long count = max(maxVal,s);
        cout << count << '\n';
    }
    return 0;
}