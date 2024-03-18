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

int gcd(int a,int b,int& x,int& y) {
    if(!b) {
        x=1,y=0;
        return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

bool any_solution(int a, int b, int c, int &x0, int &y0) {
   int g = gcd(abs(a), abs(b), x0, y0);
   if (c % g) {
   return false;
   }
   x0 *= c / g;
   y0 *= c / g;
   if (a < 0) x0 = -x0;
   if (b < 0) y0 = -y0;
   return true;
}


void shift(int & x, int & y, int a, int b, int cnt) {
   x += cnt * b;
   y -= cnt * a;
}

int all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
   int x, y, g;
   if (!any_solution(a, b, c, x, y))
   return 0;

   a /= g;
   b /= g;

   int sign_a = a > 0 ? +1 : -1;
   int sign_b = b > 0 ? +1 : -1;

   shift(x, y, a, b, (minx - x) / b);
   if(x < minx)
   shift(x, y, a, b, sign_b);
   if (x > maxx) return 0;

   int lx1 = x;
   shift(x, y, a, b, (maxx - x) / b);
   if (x > maxx)
   shift(x, y, a, b, -sign_b);

   int rx1 = x;
   shift(x, y, a, b, -(miny - y) / a);
   if (y < miny)
   shift(x, y, a, b, -sign_a);
   if (y > maxy) return 0;

   int lx2 = x;
   shift(x, y, a, b, -(maxy - y) / a);
   if (y > maxy)
   shift(x, y, a, b, sign_a);

   int rx2 = x;
   if (lx2 > rx2)swap(lx2, rx2);

   int lx = max(lx1, lx2);
   int rx = min(rx1, rx2);
   if (lx > rx)return 0;

   return (rx - lx) / abs(b) + 1;
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

