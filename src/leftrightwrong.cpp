#include <bits/stdc++.h>
using namespace std;

void solve(){
        int n;
        cin >> n;
        vector<int> vect(n);
        for(int i = 0;i < n;i++){
            cin >> vect[i];
        }
        string s;
        cin >> s;
        vector<int> sum(n);
        sum[0] = vect[0];
        for(int i = 1;i < n;i++){
            sum[i] = sum[i-1] + vect[i];
        }
        int i = 0;
        int j = s.size()-1;
        vector<pair<int,int>> p;
        while(i < j){
            if(s[i] == 'L' && s[j] == 'R'){
                s[i] = '.';
                s[j] = '.';
                p.push_back({i,j});
                i++;
                j--;
            }else if(s[i] == 'R'){
                i++;
            }else if(s[j] == 'L'){
                j--;
            }
        }
        int res = 0;
        for(int i = 0;i < p.size();i++){
            pair<int,int> val = p[i];
            int a = val.first;
            int b = val.second;
            if(a > 0){
                res += sum[b] - sum[a-1];
            }else{
                res += sum[b];
            }
        }
        cout << res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}