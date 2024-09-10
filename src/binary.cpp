#include <bits/stdc++.h>
using namespace std;
int main(){
    int l = 0;
    int r = 5;
    int val = 3;
    vector<int> v = {1,2,4,8,9};
    //lower bound
    int res;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(val >= v[mid]){
            res = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << res;
}