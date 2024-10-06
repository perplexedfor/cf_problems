#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = n*(n+1)/2;
    if(ans%2 == 1){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
        vector<int> a,b;
        int i = 1, j = n;
        int sum1 = 0;
        int half = ans/2;
        cout << half << '\n';
        while(sum1 != half && i < j){
            a.push_back(i);
            a.push_back(j);
            sum1 += i;
            sum1 += j;
            cout << sum1 << '\n';
            i++;
            j--;
        }
        for(int k = i; k <= j; k++){
            b.push_back(k);
        }
        // cout << a.size() << '\n';
        // for(int k = 0; k < a.size(); k++){
        //     cout << a[k] << ' ';
        // }
        // cout << '\n';
        // cout << b.size() << '\n';
        // for(int k = 0; k < b.size(); k++){
        //     cout << b[k] << ' ';
        // }
        // cout << '\n';
    }
}