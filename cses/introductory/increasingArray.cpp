#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    long long count = 0;
    for(int i = 1;i < n;i++){
        if(v[i] < v[i-1]){
            count += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout << count;
}