#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e4 + 5;
int n, m, color[max_n],isBipartite;
vector<int> graph[max_n];
void dfs(int i){
    for(auto &neigh : graph[i]){
        if(!color[neigh]){
            color[neigh] = 3 - color[i];
            dfs(neigh);
        }else if(color[neigh] + color[i] != 3){
            isBipartite = 0;
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        graph[i].clear();
        color[i] = 0;
    }
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    isBipartite = 1;
    color[1] = 1;
    dfs(1);
    if(!isBipartite){
        cout << "Alice" << '\n';
        for(int i = 1;i <= n;i++){
            cout << 1 << ' ' << 2 << '\n';
            int vertex, chosenColor;
            cin >> vertex >> chosenColor;
        }
    }else{
        cout << "Bob" << "\n";
        vector<int> part1,part2;
        for(int i = 1;i <= n;i++){
            if(color[i] == 1){
                part1.push_back(i);
            }else{
                part2.push_back(i);
            }
        }
        for(int i = 1;i <= n;i++){
            int color1,color2;
            cin >> color1 >> color2;
            if((color1 == 1 || color2 == 1) && part1.size()){
                cout << part1.back() << " " << 1 << endl;
            }else if((color2 == 2 || color1 == 2) && part2.size()){
                cout << part2.back() << " " << 2 << endl;
            }else if(!part1.size()){
                int choosenColor = color1 == 1 ? color2 : color1;
                cout << part1.back() << ' ' << choosenColor << endl;
            }else{
                int choosenColor = color1 == 2 ? color2 : color1;
                cout << part1.back() << ' ' << choosenColor << endl;
                part1.pop_back();
            }
        }
    }

}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}