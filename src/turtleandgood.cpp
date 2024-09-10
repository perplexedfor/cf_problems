#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;
    bool turtle = true;

    while (left < right) {
        if (turtle) {
            left++; 
        } else {
            right--;  
        }
        turtle = !turtle;
    }

    cout << v[left] << '\n';

    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> v[i];
    // }


    // stack<int> st;
    // for(int i = 0; i < n; i++) {
    //     st.push(v[i]);
    // }

    // vector<pair<int, int>> to(n);
    // for(int i = 0; i < n; i++) {
    //     to[i] = {v[i], i};
    // }
    // sort(to.begin(), to.end());

    // int i = 0, j = n - 1;
    // bool turtle = true;

    // while(st.size() > 1) {
    //     int target = turtle ? to[i].first : to[j].first;
    //     stack<int> temp;
    //     while(st.top() != target) {
    //         temp.push(st.top());
    //         st.pop();
    //     }
    //     st.pop();  
    //     while(!temp.empty()) {
    //         st.push(temp.top());
    //         temp.pop();
    //     }

    //     if (turtle) {
    //         i++;
    //     } else {
    //         j--;
    //     }
    //     turtle = !turtle;
    // }

    // cout << st.top() << '\n';

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}