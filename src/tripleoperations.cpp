#include <bits/stdc++.h>
using namespace std;


void solve(){
    int l,r;
    int n;
    cin >> l >> r;
    cin >> n;
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n = n/10;
    }
    cout << sum << '\n';
}
int main(){
    const int maxRange = 1e5;
    vector<int> number(maxRange);
    for(long long j = 0;j < maxRange;j++){
        long long cnt = 0,k = j;
        while(k > 0){
            k /= 3;
            cnt++;
        }
        number[j] = cnt;
    }
    vector<int> opSum(maxRange);
    for(long long j = 1;j < maxRange;j++){
        number[j] = number[j-1] + number[j];
    }
    int t;
    cin >> t;
    while(t--){
        long long l,r;
        cin >> l >> r;
        
    }
}