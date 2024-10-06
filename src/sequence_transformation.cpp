#include <iostream>
#include <functional>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    function<void(int,int)> answer = [&] (int n,int x){
        if(n <= 3){
            for(int i = 0;i < n-1;i++){
                cout << x << ' ';
            }
            cout << n*x << ' ';
            return;
        }
        for(int i = 0;i < n - n/2;i++){
            cout << x << ' ';
        }
        answer(n/2,2*x);
    };
    answer(n,1);
    return 0;
}