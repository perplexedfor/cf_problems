#include <bits/stdc++.h>
using namespace std;

void solve(int k) {
    long long length = 1, count = 9, start = 1;
    
    while (k > length * count) {
        k -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    
    start += (k - 1) / length;
    string num = to_string(start);
    cout << num[(k - 1) % length] << '\n';
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        solve(k);
    }
}