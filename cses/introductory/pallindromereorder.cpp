#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    for(char c : s){
        cnt[c - 'A']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 == 1){
            odd++;
        }
    }
    if(odd > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string res = "";
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 == 0){
            for(int j = 0; j < cnt[i] / 2; j++){
                res += (char)(i + 'A');
            }
        }
    }
    cout << res;
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 == 1){
            for(int j = 0; j < cnt[i]; j++){
                cout << (char)(i + 'A');
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}