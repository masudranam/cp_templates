#include<bits/stdc++.h>
using namespace std;

struct DSU{
   vector<int> p,siz;
   DSU(int n){
      p.assign(n+1,0);
      siz.assign(n+1,1);
      iota(p.begin(),p.end(),0);  
   }

   int get(int x){
      if(p[x] == x) return x;
      return p[x] = get(p[x]);
   }

   bool Merge(int a, int b){
      a  = get(a), b = get(b);
      if(a == b) return true;
      if(siz[a] < siz[b])swap(a,b);
      siz[a] += siz[b];
      p[b] = a;
      return false;
   }
};

void solve(){
   DSU dsu(10);
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

