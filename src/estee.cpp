#include <bits/stdc++.h>
using namespace std;
bool isPrime(int val){
    if(val == 1) return false;
    for(int i = 2;i*i <= val;i++){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}
unordered_map<string, int> memo;

string generateKey(int index, int current) {
    return to_string(index) + "," + to_string(current);
}

int fn(string dec, int index, int current) {
    // Create a key for the current state
    string key = generateKey(index, current);
    
    // Check if the result is already computed
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (index == dec.size()) {
        // Only count if the last segment was valid and it's the end of the string
        if (current == 0) {
            return 1;
        }
        return 0;
    }

    // Extend the current segment
    current = current * 10 + (dec[index] - '0');

    int count = 0;
    // Check if the current segment is a prime number
    if (isPrime(current)) {
        // Continue with the current segment and start a new segment
        count += fn(dec, index + 1, current);
        // Start a new segment
        count += fn(dec, index + 1, 0);
    } else {
        // Continue with the current segment
        count += fn(dec, index + 1, current);
    }

    // Store the result in the memoization map
    memo[key] = count;

    return count;
}

int main() {
    string dec;
    cin >> dec;

    // Call the recursive function with initial parameters
    int count = fn(dec, 0, 0);

    cout << count;
    return 0;
}