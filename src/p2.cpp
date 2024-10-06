#include <bits/stdc++.h>
using namespace std;

void check(int i,vector<int>&v,int csum,int cnt,vector<int>&sums){
    int n = v.size()/2;
    if(cnt == n){
        sums.push_back(csum);
    }
    if(i >= v.size()) return;
    check(i+1,v,csum+v[i],cnt+1,sums);
    check(i+1,v,csum,cnt,sums);
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    int sum = accumulate(v.begin(),v.end(),0);
    int mid = sum/2;

    vector<int> sums;
    check(0,v,0,0,sums);
    int diff = INT_MAX;
    for(int i = 0;i < sums.size();i++){
        if(abs(sums[i]-(sum - sums[i])) < diff){
            diff = abs(2*sums[i]-sum);
        }
    }
    cout << diff << endl;
}