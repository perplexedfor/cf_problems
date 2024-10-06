#include <bits/stdc++.h>
using namespace std;

// Function to calculate the number of operations needed to match the target sum for each subarray
long long check(const vector<int>& arr, int k, long long target) {
    long long op = 0; // Initialize operations count

    // Loop through subarrays of length k
    for (int i = 0; i <= (int)arr.size() - k; i = i+k) {
        long long curr = 0; // Current subarray sum
        for (int j = i; j < i + k; j++) {
            curr += arr[j];
        }

        long long diff = curr - target;
        op += abs(diff); // Increment the operations by the absolute difference
    }

    return op;
}

int main() {
    int n, k;
    cin >> n; // Number of files

    vector<int> filesize(n);

    for (int i = 0; i < n; i++) {
        cin >> filesize[i]; // File sizes
    }

    cin >> k; // Number of consecutive files

    long long l = 0; // Lower bound
    long long h = 1e12; // Upper bound (Assuming the upper bound is sufficiently large to avoid overflow)
    long long res = LLONG_MAX; // Initialize the result with a very large number

    // Binary search on possible target sums
    while (l <= h) {
        long long mid = l + (h - l) / 2;

        long long val = check(filesize, k, mid); // Calculate operations for current mid (target sum)
        res = min(res,val);
        if (val < res) {
            h = mid - 1; // Move to the right if more operations are required
        } else {
            l = mid + 1; // Move to the left otherwise
        }
    }

    cout << res << endl; // Output the result

    return 0;
}
//wrong no binary search okay
