#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> ch = {'a','e','i','o','u'};
    string s = "";
    int i = 0;
    int each = n/5;
    int rem = n%5;
    while(i < 5){
        int temp = each;
        while(temp){
            s += ch[i];
            temp--;
        }
        if(rem){
            s += ch[i];
            rem--;
        }
        i++;
    }
    cout << s << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}