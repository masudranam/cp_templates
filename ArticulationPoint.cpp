#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int in[N],low[N],timer;
vector<int> g[N], cut_vertex;

 void dfs(int u,int p=-1){
     in[u] = low[u] = ++timer;
     for(auto v:g[u]){
        if(v == p)continue;
        if(in[v] == 0){
        dfs(v,u);
        low[u]=min(low[v],low[u]); 
        if(low[v]>= in[u] && p!= -1)
            cut_vertex.push_back(u);
        } else{
         low[u]=min(low[u],in[v]);
        }
   }
   if(p == -1 && g[u].size() > 1){
    cut_vertex.push_back(u);
   }
 }
void solve(){

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

