#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--){
        long long i,j;
        cin >> i >> j;
        if(i > j){
            if(i%2 == 0){
                cout << i*i - j + 1;
            }else{
                cout << (i-1)*(i-1) + j;
            }
        }else{
            if(j%2 == 0){
                cout << (j-1)*(j-1) + i;
            }else{
                cout << j*j - i + 1;
            }
        }
        cout << '\n';
    }
}