#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n != 1) {
        if (n & 1) {  // If n is odd
            cout << n << " ";
            n = 3 * n + 1;
        } else {
            while (n != 1 && (n % 2 == 0)){
                cout << n << " ";
                n /= 2;
            };
        }
    }

    cout << 1; 
    return 0;
}