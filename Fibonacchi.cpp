#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

pair<int,int> fib(int n) {
    if(!n) {
        return {0,1};
    }
    auto p=fib(n>>1);
    int c=p.first*(2*p.second-p.first);
    int d=p.first*p.first+p.second*p.second;
    if(n&1)
        return {d,c+d};
    else return {c,d};
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

