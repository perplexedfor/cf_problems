#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int countTen = 0;
    int countFive = 0;
    int countTwo = 0;
    

    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp % 10 == 0){
            countTen++;
            temp /= 10;
        }
        while(temp % 5 == 0){
            countFive++;
            temp /= 5;
        }
        while(temp % 2 == 0){
            countTwo++;
            temp /= 2;
        }
    }
    
    cout << countTen + min(countFive,countTwo) << endl;
    return 0;
}