#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,h,r;
    cin >> a >> h >> r;
    vector<int> aW(a);
    vector<int> hW(h);
    for(int i = 0;i < a;i++){
        cin >> aW[i];
    }
    for(int i = 0;i < h;i++){
        cin >> hW[i];
    }
    sort(aW.begin(),aW.end());
    sort(hW.begin(),hW.end());
    int i = 0;
    int j = 0;
    int res = 0;
    while(j < h && i < a){
        int s = hW[j];
        int a = aW[i];
        if(s <= a + r && s >= a - r){
            i++;
            j++;
            res++;
        }else if(s < a-r){
            j++;
        }else{
            i++;
        }
    }
    cout << res;
}