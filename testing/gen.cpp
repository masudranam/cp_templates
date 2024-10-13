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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

void solve(){
		int n = random(500, 500);
      cout << n <<'\n';
      for(int i = 0; i < n; i++){
         cout << random(10000, 300000) <<' ';
      }

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

