#include<bits/stdc++.h>
using namespace std;

struct ST{
    int n;
    const int LOG = 22;
    vector<int> a,pw;
    vector<vector<int>>mx,mn;

    ST(vector<int> _a){
        a = _a; n = (int)a.size();  pw = vector<int>(n+10);
        mx = mn = vector<vector<int>>(n+1,vector<int>(LOG+1));

        pw[1] = 0;
        for(int i = 2; i <= n; i++){
            pw[i] = pw[i/2] + 1;
        }
        for(int i = 0; i < n; i++){
            mx[i][0] = mn[i][0] = a[i];
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; (i+(1<<k)-1) < n; i++){
                mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            }
        }
    }
    
        int qmx(int l, int r){
            int k = pw[r-l+1];
            return max(mx[l][k],mx[r-(1<<k)+1][k]);            
        }
        int qmn(int l, int r){
            int k = pw[r-l+1];
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        }
};

void solve(){
   vector<int> a{1,2,3};
   ST st(a);
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

