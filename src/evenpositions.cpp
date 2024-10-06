#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> st;
    int sum = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '_'){
            if(st.size() == 0){
                st.push(i);
            }else{
                int j = st.top();
                st.pop();
                sum += i - j;
            }
        }else if(s[i] == ')'){
            int j = st.top();
            st.pop();
            sum += i - j;
        }else if(s[i] == '('){
            st.push(i);
        }
    }
    cout << sum << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}