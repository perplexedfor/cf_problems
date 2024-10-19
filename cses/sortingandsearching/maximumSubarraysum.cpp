#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    long long curSum = 0;
    long long maxSum = 0;
    for(int i = 0;i < n;i++){
        curSum += v[i];
        if(curSum < 0){
            curSum = 0;
        }
        maxSum = max(maxSum,curSum);
    }
    if(count_if(v.begin(),v.end(),[](long long a){ return a < 0; }) == n) maxSum = *max_element(v.begin(),v.end());
    cout << maxSum;
}