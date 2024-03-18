#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int vis[N],col[N];

bool Bipart(int u,int c=0){
 vis[u]=1;
 col[u]=c;
 for(auto v:g[u]){
    if(!vis[v]){
        if(!Bipart(v,c^1))return false;
    }else if(col[v]==col[u])return false;
 }
 return true;
 }
 
void solve(){

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

