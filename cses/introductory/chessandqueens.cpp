#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v(8,vector<int>(8,0));
    for(int i = 0;i < 8;i++){
        string s;
        cin >> s;
        for(int j = 0;j < 8;j++){
            if(s[j] == '*') v[i][j] = -1;
        }
    }
    int ways = 0;
    auto checkWays = [&](auto self,int y){
        if(y == 8){
            ways++;
            return;
        }
        for(int i = 0;i < 8;i++){
            if(v[i][y] == -1) continue; 
            bool valid = true;
            for(int k = 0;k < 8;k++){
                for(int j = 0;j < 8;j++){
                    if(v[k][j] != 1) continue;
                    if(k == i || j == y || abs(k - i) == abs(j - y)){
                        valid = false;
                        break;
                    }
                }
                if(!valid) break;
            }
            if(valid){
                v[i][y] = 1;
                self(self,y+1);
                v[i][y] = 0;
            }
            
        }

    };
    checkWays(checkWays,0);
    cout << ways;
    return 0;
}