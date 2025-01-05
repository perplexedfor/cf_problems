#include <vector>
#include <string>
#include <numeric>
using namespace std;

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //stl partial sum the line sweep plus prefix sum a unique combo
        int n = s.size();
        vector<int> apply(n+1,0);
        for(auto &it : shifts){
            int l = it[0];
            int r = it[1];
            int d = it[2] == 1 ? 1 : -1;
            apply[l] += d;
            apply[r+1] -= d; 
        }
        partial_sum(apply.begin(),apply.end(),apply.begin());
        for(int i = 0;i < n;i++){
            char& c = s[i];
            c = (apply[i] + c - 'a')%26 + 'a';
            if(c < 'a'){
                c += 26;
            }
        }
        return s;
    }