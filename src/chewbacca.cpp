#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long res = 0;
    int i = 0;

    while (n != 0) {
        int digit = n % 10;
        if (digit == 9 && n / 10 == 0) {
            res = digit * pow(10, i) + res;
            break;
        }
        if (digit > 4) {
            digit = 9 - digit;
        }
        res = digit * pow(10, i) + res;
        n = n / 10;
        i++;
    }
    cout << res << endl;
    return 0;
}