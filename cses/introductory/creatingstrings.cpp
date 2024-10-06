#include <bits/stdc++.h>
using namespace std;

void recur(string&s,string& curr,int i,vector<string>&res,vector<bool>&taken){
    if(i == s.size()){
        res.push_back(curr);
        return;
    }
    for(int j = 0;j < s.size();j++){
        if(taken[j]) continue;
        curr.push_back(s[j]);
        taken[j] = true;
        recur(s,curr,i+1,res,taken);
        taken[j] = false;
        curr.pop_back();
    }
}

int main(){
    string s;
    cin >> s;
    
    // sort(s.begin(),s.end());
    int n = s.size();
    vector<string> res;
    string curr;
    vector<bool> taken(n,false);

    recur(s,curr,0,res,taken);
    cout << res.size() << endl; 
    for(auto &it : res){
        cout << it << '\n';
    }
}