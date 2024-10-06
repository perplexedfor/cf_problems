#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    int x = 0;
    for(int i = 0;i < n;i++){
        if(s[i][0] == '+' || s[i][1] == '+'){
            x++;
        }else{
            x--;
        }
    }
    cout << x;
}