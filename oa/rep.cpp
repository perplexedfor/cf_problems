#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

string replaceString(string s, const string& substr) {
    int n = s.length();
    int m = substr.length();
    
    if (m > n) return "-1";

    vector<int> lps = computeLPS(substr);
    int i = 0, j = 0;
    
    while (i < n) {
        if (s[i] == substr[j] || s[i] == '?') {
            i++;
            j++;
        }

        if (j == m) {
            // Match found, replace and return
            for (int k = 0; k < m; k++) {
                s[i - m + k] = substr[k];
            }
            for (int k = 0; k < n; k++) {
                if (s[k] == '?') s[k] = 'a';
            }
            return s;
        } else if (i < n && (s[i] != substr[j] && s[i] != '?')) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return "-1";
}

int main() {
    string s, substr;
    cin >> s >> substr;
    
    string result = replaceString(s, substr);
    cout << result << endl;
    
    return 0;
}