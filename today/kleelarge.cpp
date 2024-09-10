#include <iostream>
using namespace std;

// Function to calculate the val1 and val2 as per the given formula
pair<long long, long long> val(long long mid, long long k, long long n) {
    long long val1 = (mid + k - 1 + k) * mid / 2;
    long long val2 = (k + n - 1 + k) * n / 2 - val1;
    return {val1, val2};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long lo = 1, hi = n, curr = 1;

        // Binary search to find the optimal value for curr
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            auto [a, b] = val(mid, k, n);
            
            if (b > a) {
                curr = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Calculate for curr and curr+1 to get the final result
        auto [a1, b1] = val(curr, k, n);
        auto [a2, b2] = val(curr + 1, k, n);

        cout << min(b1 - a1, a2 - b2) << endl;
    }

    return 0;
}
