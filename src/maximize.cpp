#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int maxVal = 0;
        for(int i = 1;i <= n;i++){
            int val;
            cin >> val;
            if(i&1){
                maxVal = max(maxVal,val);
            }
        }
        cout << maxVal << '\n';
    }
}