#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a == b){
            if(a % 3 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(a > b){
            if((a+b) % 3 == 0 && 2*b >= a){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if((a+b) % 3 == 0 && 2*a >= b){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}