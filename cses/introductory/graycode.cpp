#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> res;
    res.push_back("0");
    res.push_back("1");
    for(int i = 2;i <= n;i++){
        vector<string> temp;
        for(int i = 0;i < res.size();i++){
            temp.push_back("0"+res[i]);
        }
        for(int i = res.size()-1;i >= 0;i--){
            temp.push_back("1"+res[i]);
        }
    }
    return 0;
}