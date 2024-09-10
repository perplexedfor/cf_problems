#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& v, vector<int>& minVal, int i, int j) {
    if (i == j) {
        return minVal[i + j] = v[i];
    }
    int mid = (i + j) / 2;
    return minVal[i + j] = min(dfs(v, minVal, i, mid), dfs(v, minVal, mid + 1, j));
}

int main() {
    vector<int> v = {1, 3, 4, 8, 6, 1, 4, 2};
    int n = v.size();
    
    // To store the results of the minimum values between ranges
    vector<int> minVal(n * 2, INT_MAX);
    
    // Find the nearest power of 2 less than or equal to n
    int i = 0;
    while ((1 << i) <= n) {
        i++;
    }
    int k = 1 << (i - 1);  // k is the largest power of 2 less than or equal to n
    
    // Apply dfs to fill the minVal vector
    for (int j = k; j < n; j++) {
        dfs(v, minVal, j - k, j - 1);
    }
    
    // Example of getting minimum between two values
    int query1 = min(minVal[1 + 1 + 4 - 1], minVal[6 - 4 + 1 + 6]); // adjust the logic to fit your needs
    
    cout << "Min of example query: " << query1 << endl;
    return 0;
}