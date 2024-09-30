#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

//KMP 
vector<int> prefix_function (string s) {
   int n = (int) s.length();
   vector<int> pi (n);
   for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j])
         j = pi[j - 1];
      if (s[i] == s[j])
         j++;
      pi[i] = j;
      }
 return pi;
 }


void solve(){

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
