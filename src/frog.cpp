#include <iostream>
#include <algorithm>
using namespace std;


void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int cx = x/k;
    if(x%k != 0){
        cx++;
    }
    int cy = y/k;
    if(y%k != 0){
        cy++;
    }
    if(cx > cy){
        cout << cx + cx - 1 << '\n';
    }else{
        cout << cy + cy << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
