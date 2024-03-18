#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<array<int,2>>g[N];
void dijkstra(int src) {
    vector<int>d(N,M);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    d[src]=0;
    q.push({0,src});
    while(q.size()) {
        array<int,2> u=q.top();
        q.pop();
        if(u[0]>d[u[1]])continue;
        for(array<int,2>v:g[u[1]]) {
            if(d[v[1]]>u[0]+v[0]) {
                d[v[1]]=u[0]+v[0];
                q.push({d[v[1]],v[1]});
            }
        }
    }
}

void solve(){

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

