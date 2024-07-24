#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2;i*i < n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
vector<bool> sieve(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i*i <= n;i++){
        if(isPrime[i]){
            for(int j = i*i;j <= n;j+= i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
vector<pair<int,int>> primeFactors(int n){
    vector<pair<int,int>> ans;
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n = n/i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(n > 1) ans.push_back({n,1});
    return ans;
}
int main(){
    return 0;
}