#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
    vector<T> tree;
    int n;

    fenwick_tree(int _n) : n(_n) {
        tree.resize(n + 1, 0);
    }
    void init() {
        fill(tree.begin(), tree.end(), 0);
    }

    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }

    T sum(int idx) {
        T result = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            result += tree[idx];
        return result;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (auto &num: nums) cin >> num, num --;

    fenwick_tree<long long> fen(n);
    vector<long long> dp(n, 1);

    for (int _ = 0; _ < k; _ ++) {
        fen.init();
        for (int i = 0; i < n; i ++) {
            fen.add(nums[i], dp[i]);
            dp[i] = fen.sum(0, nums[i]);
        }
    }
    long long ans = 0;
    for (auto &x: dp) ans += x;
    cout << ans;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// unordered_map<string, int> memo;

// int recur(vector<int>& A,int k,int i,int prev,int size){
//     if(size == k){
//         return 1;
//     }
//     if (i >= A.size()) {
//         return 0;
//     }
//     string key = to_string(i) + "," + to_string(prev) + "," + to_string(size);
//     if (memo.find(key) != memo.end()) {
//         return memo[key];
//     }
//     int res;
//     if(prev == -1){
//         res = recur(A,k,i+1,A[i],size+1) + recur(A,k,i+1,prev,size);
//     }
//     if(prev < A[i]){
//         res = recur(A,k,i+1,prev,size) + recur(A,k,i+1,A[i],size+1);
//     }else{
//         res = recur(A,k,i+1,prev,size);
//     }
//     return memo[key] = res;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n,k;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for(auto &num: nums) cin >> num;
//     cout << recur(nums,k+1,0,-1,0) << endl;
//     return 0;
// }