#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // at each step subtract one of the digit from the number and return the number of steps req
    int steps = 0;
    while(n != 0){
        int temp = n;
        int sub = 0;
        while(temp){
            int v = temp%10;
            temp = temp/10;
            sub = max(v,sub);
        }
        n -= sub;
        steps++;
    }
    cout << steps;
}