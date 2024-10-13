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
    vector<int> a(n + 1);
    vector<int> dp(n+1, M * M);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<int,int> mp, cur;
    for(int i = 1; i <= n; i++){
        cur.clear();
        dp[i] = min(dp[i], dp[i - 1] + a[i]);

        for(auto it : mp){
            int id = it.second;
            int x = it.first;
            int l = lcm(x, a[i]);
            if(l > 1e13)continue;

            if(cur.find(l) != cur.end()){
                cur[l] = min(cur[l], id);
            }else{
                cur[l] = id;
            }
           
            dp[i] = min(dp[i], dp[id - 1] + l);
        }
        if(cur.find(a[i]) == cur.end()){
            cur[a[i]] = i;
        }
        mp = cur;
    }
    cout << dp[n] << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
