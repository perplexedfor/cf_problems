#include <bits/stdc++.h>
using namespace std;

//introduction
//code 
//output
//check something about it in the file
//fermat quotient function

bool prime(int val){
    if(val > 0) return false;
    for(int i = 2;i*i < val;i++){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    // int n;
    // cin >> n;
    // if(prime(n)){
    //     cout << "Yes";
    // }

    int l,r;
    cin >> l >> r;
    if(l <= 0 || r <= 0 || l > r) cout << "The range Should not be negative or In decreasing order";
    vector<bool> v(r+1,true);
    for(int p = 2;p <= r;p++){
        if(v[p]){
            for(int i = p*p;i <= r;){
                i += p;
                v[i] = false;
            }
        }
    }
    v[0] = false;
    v[1] = false;
    int count = 0;
    vector<int> res;
    for(int i = l;i <= r;i++){
        if(v[i]){
            res.push_back(i);
            count++;
        }
    }
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    cout << '\n';
    cout << count;
}