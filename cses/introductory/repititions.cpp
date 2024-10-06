#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int maxLen = 0;
    int count = 0;
    char prev = '#';
    for(int i = 0;i < s.size();i++){
        if(count == 0){
            prev = s[i];
            count++;
        }else{
            if(prev == s[i]){
                count++;
            }else{
                count = 1;
                prev = s[i];
            }
        }
        maxLen = max(count,maxLen);
    }
    cout << maxLen;
}