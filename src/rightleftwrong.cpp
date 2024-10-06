#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    string s;
    cin >> s;
    vector<long long> sum(n);
    sum[0] = v[0];
    for(int i = 1;i < n;i++){
        sum[i] = sum[i-1] + v[i];
    }
    long long res = 0;
    int i = 0;
    int j = n-1;
    while(i < j){
        if(s[i] == 'L' && s[j] == 'R'){
            if(i == 0){
                res += sum[j];
            }else{
                res += sum[j] - sum[i-1];
            }
            i++;
            j--;
        }else if(s[i] == 'R'){
            i++;
        }else if(s[j] == 'L'){
            j--;
        }
    }
    cout << res << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}