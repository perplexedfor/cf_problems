#include <bits/stdc++.h>
using namespace std;

bool query(int i,int j,int ans = 0){
    cout << "? " << i << " " << j << endl;
    cin >> ans;
    return ans;
}

int main(){
    int tt;
    for(cin >> tt;tt;--tt){
        int n,N;cin >> N;n = N;
        vector<int> candidates = {-1,-1};

        while(n > 4){
            if(query(n-1,n) != query(n,n-1)){
                candidates = {n-1,n}; break;
            }else n -= 2;
        }

        if(candidates[0] != -1){
            int not_candidate = (candidates[0] == N-1) ? N-2 : N;

            if(query(candidates[0],not_candidate) != query(not_candidate,candidates[0])){
                cout << "! " << candidates[0] << '\n';
            }else cout << "! " << candidates[1] << '\n';
        }else{
            if(n == 3){
                if(query(3,2) == query(2,3)){
                    cout << "! 1\n";
                }else{
                    if(query(1,3) == query(3,1)){
                        cout << "! 2\n";
                    }else{
                        cout << "! 3\n";
                    }
                }
            }else{
                if(query(1,2) != query(2,1)){
                    if(query(1,3) == query(3,1)) cout << "! 2\n";
                    else cout << "! 1\n";
                }else{
                    if(query(1,3) != query(3,1)){
                        cout << "! 3\n";
                    }else{
                        cout << "! 4\n";
                    }
                }
            }
        }
    }
}