#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int lcm(int a, int b){
   return (a / __gcd(a, b)) * b;
}

void solve(){
    int n; cin >> n;

    vector<int> a(n + 1), dp(n + 1, M * N);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
      dp[i] = min(dp[i], dp[i - 1] + a[i]);
      int x = a[i];
      for(int j = i - 1; j >= 1; j--){
         x = lcm(x, a[j]);
         if(x > 1e13)break;
         dp[i] = min(dp[i], dp[j - 1] + x);
      }
    }
    cout << dp[n] << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
//   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
