#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<vector<int>>> t;
    for(int i = 0;i < n;i++){
        int x,y;
        cin >> x >> y;
        vector<vector<int>> res(x,vector<int>(y));
        for(int i = 0;i < x;i++){
            for(int j = 0;j < y;j++){
                cin >> res[i][j];
            }
        }
        t.push_back(res);
    }
    for (int i = 0; i < t.size(); i++) {
        vector<vector<int>>& res = t[i];
        for (int r = 0; r < res.size(); r++) {
            int temp = res[r][0];
            for (int c = 0; c < res[r].size() - 1; c++) {
                res[r][c] = res[r][c + 1];
            }
            res[r][res[r].size() - 1] = temp;
        }
    }
    for(int i = 0;i < t.size();i++){
        vector<vector<int>>& res = t[i];
        if(res.size() == 1 && res[0].size() == 1){
            cout << "-1" << endl;
        }else{
            for(int j = 0;j < res.size();j++){
                for(int k = 0;k < res[0].size();k++){
                    cout << res[j][k] << " ";
                }
                cout << "\n";
            }
        }
    }
}