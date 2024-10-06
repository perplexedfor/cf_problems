#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> range(n, vector<int>(4)); // Initialize a 2D vector with n rows and 4 columns

    // Reading the input values
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> range[i][j];
        }
    }

    // Processing and output
    for(int i = 0; i < n; i++){
        cout << range[i][1] << " " << range[i][2] << " " << range[i][2] << endl;
    }

    return 0;
}
