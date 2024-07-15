#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double ax, ay, bx, by, tx, ty, x, y;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    auto f1 = [&] () {
        return hypot(x - ax, y - ay);
    };

    auto f2 = [&] () {
        return hypot(x - bx, y - by);
    };

    auto f = [&] () {
        return hypot(x - tx, y - ty);
    };

    double ans = 0, dp1 = 4e9, dp2 = 4e9, dp3 = 4e9;
    int n;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        ans += 2 * f();
        double v1 = f1() - f(), v2 = f2() - f();
        dp3 = min({dp3, dp1 + v2, dp2 + v1});
        dp2 = min(dp2, v2);
        dp1 = min(dp1, v1);
    }
    cout << setprecision(15) << ans + min({dp1, dp2, dp3}) << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// double fn(pair<int,int>& t,vector<vector<int>>& cans){
//     double res = 0;
//     for(const auto can : cans){
//         res += sqrt(pow(can[0] - t.first,2)+ pow(can[0]-t.second,2));
//     }
//     return res;
// }
// double role(pair<int,int> p1,int d1,pair<int,int> p2,int d2,vector<vector<int>> &cans){
//     if(d1 == 0 && d2 == 0) return 0;
//     double res = INT_MAX;
//     for(const auto can: cans){
//         if(d1 != 0){
//             res = min(res,sqrt(pow(can[0] - p1.first,2)+ pow(can[0]-p1.second,2))+ role(p1,0,p2,d2,cans));
//         }
//         if(d2 != 0){
//             res = min(res,sqrt(pow(can[0] - p2.first,2)+ pow(can[0]-p2.second,2))+ role(p1,d1,p2,0,cans));
//         }
//     }
//     return res;
// }
// int main(){
//     pair<int,int> p1;
//     pair<int,int> p2;
//     pair<int,int> t;
//     int N;
//     cin >> p1.first >> p1.second >> p2.first >> p2.second >> t.first >> t.second;
//     cin >> N;
//     vector<vector<int>> cans(N,vector<int>(2));
//     for(auto &can : cans){
//         cin >> can[0] >> can[1];
//     }
//     double sum;
//     sum = fn(t,cans);
//     cout << sum + role(p1,1,p2,1,cans);
// }