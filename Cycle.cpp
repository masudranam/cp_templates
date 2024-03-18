#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int>g[N];
int b,e,vis[N],par[N];

bool isCycDG(int u) {
    vis[u]=1;
    for(int v:g[u]) {
        if(!vis[v]) {
            par[v]=u;
            if(isCycDG(v))return true;
        } else if(vis[v]==1) {
            b=v,e=u;
            return true;
        }
    }
    vis[u]=2;
    return false;
}

bool isCycUG(int u,int p=-1) {
    vis[u]=1;
    for(auto v:g[u]) {
        if(!vis[v]) {
            par[v]=u;
            if(isCycUG(v,u))return true;
        } else if(v!=p) {
            b=v,e=u;
            return true;
        }
    }
    return false;
}

vector<int> find_cycle(int n) {
    b=-1;
    for (int v = 1; v <= n; v++) {
        if (vis[v] == 0 &&  isCycUG(v))
            break;
    }
    if (b==-1) {
        return vector<int>();
    } else {
        vector<int> cycle;
        for (int v = e; v != b; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(b);
        reverse(cycle.begin(),cycle.end());
        return cycle;
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

