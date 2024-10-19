#include <bits/stdc++.h>
using namespace std;
int findCommon(string a,string b){
    int i = 0;
    for(i ;i < b.size();i++){
        if(a[i] != b[i]){
            break;
        }
    }
    return i;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a;
        cin >> b;
        int a1 = a.size();
        int b1 = b.size();
        int i;
        if(a1 >= b1){
            i = findCommon(a,b);
        }else{
            i = findCommon(b,a);
        }
        if(i == 0){
            cout << a1+b1 << '\n';
        }else{
            cout << a1 + b1 - i + 1 << '\n';
        }   
        
    }
}