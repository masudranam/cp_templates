#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

//kusarajus algo for SCC 
vector<int> g[N],gr[N];
vector<int> vis,order,cmp;

void dfs1(int u){
   vis[u] = 1;
   for(auto v: g[u]){
      if(!vis[v])dfs1(v);
   }
   order.push_back(u);
}

void dfs2(int u){
   vis[u] = 1;
   cmp.push_back(u);
   for(auto v: gr[u]){
      if(!vis[v])dfs2(v);
   }
}

void solve(){
   int n, m; 
   cin >> n >> m;

   for(int i = 0; i < m; i++){
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      gr[v].push_back(u);
   }

   vis.resize(n+1,0);

   for(int i = 1; i <= n; i++){
      if(!vis[i])dfs1(i);
   }

   reverse(all(order));
   vis = vector<int>(n+1,0);

   for(auto v: order){
      if(!vis[v]){
         cmp.clear();
         dfs2(v);
         print(cmp);
      }
   }
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

