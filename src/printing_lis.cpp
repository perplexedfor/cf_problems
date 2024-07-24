#include <bits/stdc++.h>
using namespace std;

// int lis(int arr[],int n){
//     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//     for(int ind = n-1;ind >=0;ind--){
//         for(int prev = ind-1;prev >= -1;prev--){
//             int notTake = 0 + dp[ind+1][prev+1];
//             int take = 0;
//             if(prev == -1 || arr[ind] > arr[prev]){
//                 take = 1 + dp[ind+1][ind+1];
//             }
//             dp[ind][prev+1] = max(take,notTake);
//         }
//     }
//     return dp[0][0];
// }
int lis(int arr[],int n){
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    for(int i = 0;i <= n-1;i++){
        hash[i] = i;
        for(int prev = 0;prev <= i-1;prev++){
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }
    int ans = -1;
    int lastIndex = -1;
    for(int i = 0;i <= n-1;i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    cout<<"The subsequence elements are ";
    
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    
    return ans;
}
int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"The length of the longest increasing subsequence is "
        <<lis(arr,n);
	
	return 0;
}