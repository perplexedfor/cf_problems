#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int temp = n;
    int size = 0;
    vector<int> arr;
    while(temp){
        arr.push_back(temp%10);
        temp = temp/10;
        size++;
    }
    reverse(arr.begin(),arr.end());
    int s = arr.size();
    if(s == 1 && arr[0] == 1){
        cout << "YES" << '\n';
        return;
    }
    if(s < 2){
        cout << "NO" << '\n';
        return;
    }
    if(arr[0] != 1 || arr[1] != 0){
        cout << "NO" << '\n';
        return;
    } 
    if((s > 2 && arr[2] == 0) || (arr[2] == 1 && s == 3)){
        cout << "NO" << '\n';
        return;
    } 
    cout << "YES" << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}