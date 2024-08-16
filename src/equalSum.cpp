#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i = 0;i < n;i++){
        cin >> vect[i];
    }
    rotate(vect.begin(),vect.begin()+1,vect.end());
    for(int &i : vect) cout << i << " ";
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}