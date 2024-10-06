#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& res,int p) {
    int n;
    cin >> n;
    vector<int> v(n);
    bool same = true;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i > 0 && (v[i] & 1) != (v[i-1] & 1)) {
            same = false;
        }
    }

    if(same) {
        return;
    }

    sort(v.begin(), v.end());

    int biggestOdd = -1;
    int index = -1;

    for(int i = n - 1; i >= 0; i--) {
        if(v[i] & 1) {
            biggestOdd = v[i];
            index = i;
            break;
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] % 2 == 0) {

            if(biggestOdd > v[i]){
                count++;
                v[i] = v[i] + v[index];
                if(v[i] > biggestOdd){
                    biggestOdd = v[i];
                    index = i; 
                }
            }
            else if(v[i] > biggestOdd) {
                while(v[index] < v[i]) {
                    v[index] = v[i] + v[index];
                    biggestOdd = v[index];
                    count++;
                }
                v[i] = v[index] + v[i];
                biggestOdd = max(biggestOdd,v[i]);
                index = i;
                count++;
            }
        }
    }
    res[p-1] = count;
}
int main(){
    int t;
    cin >> t;
    int k = t;
    vector<int> res(t,0);
    while(t--){
        solve(res,k-t);
    }
    for(int i = 0;i < res.size();i++){
        cout << res[i] << "\n";
    }
}
