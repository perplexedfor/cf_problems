#include <bits/stdc++.h>
using namespace std;
int cal(int a,int b,int c){
    return a*b + b*c + c*a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    while(k--){
        int n,x;
        cin >> n >> x;
        int count = 0;
        for(int a = 1;a <= min(n,x);a++){
            for(int b = 1;b*a <= n && b+a <= x;b++){
                int hightsC = min((n- a*b)/(a+b),x-(a+b));
                count += hightsC;
            }
        }
        cout << count << "\n";
    }
    return 0;
}