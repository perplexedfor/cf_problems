#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = (n*(n+1))/2;
    long long i = 1;
    vector<int> a,b;
    bool t = ans&i;

    if(t){
        cout << "NO" << '\n';
        return 0;
    }else{
        cout << "YES" << '\n';

        int k = n;
        while(k > 4){
            a.push_back(k);
            a.push_back(k-3);
            b.push_back(k-1);
            b.push_back(k-2);
            k -= 4;
        }
        if(k == 4){
            a.push_back(1);
            a.push_back(4);
            b.push_back(2);
            b.push_back(3);
        }else if(k == 3){    
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
        }
    }
    cout << a.size() << '\n';
    for(long unsigned i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
    cout << b.size() << '\n';
    for(long unsigned i = 0; i < b.size(); i++){
        cout << b[i] << ' ';
    }
    cout << '\n';

}