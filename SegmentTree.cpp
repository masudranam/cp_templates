#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;


struct node {
    int mn,s,mx,lz;
    node(int x = 0){
        mx = -M, mn = M, s = x, lz = 0;
    }
};

struct ST {
    vector<node> t;  
    int n;
    ST(int _n){
        n = _n; t.assign(4*n + 10, node());
    }

    node Merge(node a, node b){
        node res;
        res.s = min(a.s , b.s);
        return res;
    }

    void upd(int L,int x,int i,int l,int r) {
        if(l==r) {
            t[i].s += x;
            return;
        }
        int m = (l+r)/2;
        if(L <= m) upd(L, x, 2*i, l, m);
        else upd(L, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i], t[2*i+1]);
    }
    void upd(int l, int val){
        upd(l,val,1,0,n-1);
    }

    node qry(int L,int R,int i,int l,int r) {
        if(l >= L && r <= R) return t[i];
        if(l > R || r < L)return node();
        int m=(l+r)/2;

        node left , right;
        if(L <= m)left = qry(L, R, 2*i, l, m);
        if(m < R)right = qry(L, R, 2*i+1, m+1, r);
        return Merge(left, right);
    }
    node qry(int l, int r){
        return qry(l,r,1,0,n-1);
    }

     void prop(int i, int l, int r){
         if(l == r || t[i].lz == 0) return;  
         t[2 * i].s += t[i].lz;
         t[2 * i].lz += t[i].lz;
         t[2 * i + 1].s += t[i].lz;
         t[2 * i + 1].lz += t[i].lz;
         t[i].lz = 0;  
     }

    void upd1(int L, int R, int x, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return;
        if(L <= l && r <= R) {
            t[i].lz += x;
            t[i].s += x;
            return;
        }
        int m=(l+r)/2;
        upd1(L, R, x, 2*i, l, m);
        upd1(L, R, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i] , t[2*i+1]);
    }

    void upd1(int L, int R, int x){
        return upd1(L,R,x,1,0,n-1);
    }

    node qry1(int L, int R, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return node(1);
        if(L<=l && r<=R){
            return t[i];
        }
        int m = (l+r)/2;
        node left , right;
         left = qry1(L, R, 2*i, l, m);
         right = qry1(L, R, 2*i+1, m+1, r);
        return Merge(left, right);
    }

    node qry1(int L, int R){
        return qry1(L,R,1,0,n-1);
    }    
};

int tree[4 * N];
int lazy[4 * N];
void build(int i, int l, int r){
    if(l == r)tree[i] = l, lazy[i] = 0;
    else{
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        lazy[i] = 0;
    }
}

void prop(int x, int lx, int rx) {
  if (lx == rx || lazy[x] == 0) return;
  lazy[x << 1] += lazy[x];
  lazy[x << 1 | 1] += lazy[x];
  tree[x << 1] += lazy[x];
  tree[x << 1 | 1] += lazy[x];
  lazy[x] = 0;
}
void update(int x, int lx, int rx, int l, int r, int v) {
  prop(x, lx, rx);
  if (lx > r || l > rx) return;
  if (l <= lx && r >= rx) {
    tree[x] += v;
    lazy[x] += v;
    return;
  }
  int mx = (lx + rx) >> 1;
  update(x << 1, lx, mx, l, r, v);
  update(x << 1 | 1, mx + 1, rx, l, r, v);
  tree[x] = min(tree[x << 1], tree[x << 1 | 1]);
}

int query(int x, int lx, int rx, int l, int r) {
    prop(x, lx, rx);
    if( l<= lx && r <= rx) return tree[x];
    if(rx < l || r < lx) return 1;
    int m = (lx + rx) / 2;
    int a = query(x * 2, lx , m, l, r);
    int b = query(x * 2 + 1, m + 1 , rx,  l, r);
    return min(a, b);
}

void solve(){
   ST st(100);
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

