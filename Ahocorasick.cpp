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

int trie[N][26],nxt[N][26];
int d[N],par[N],pl[N],sl[N];
int node;
vector<int>tr[N];

int add(string &s){
    int cur=1;
    for(int i=0; i<sz(s); i++){
        int c=s[i]='a';
        if(!trie[cur][c])trie[cur][c]=++node,par[node]=cur,d[node]=d[cur]+1,pl[node]=c;
        cur=trie[cur][c];
    }
    return cur;
}

void push_links(){
    queue<int>q;q.push(1);
    while(sz(q)){
        int u=q.front();q.pop();
        if(d[u]<=1)sl[u]=1;
        else{
            int v=sl[par[u]],l=pl[u];
            while(v>1 && !trie[v][l])v=sl[v];
            if(trie[v][l])v=trie[v][l];
            sl[u]=v;
        }
        if(u!=1)tr[sl[u]].push_back(u);
        for(int i=0;i<26;i++){
            if(trie[u][i])q.push(trie[u][i]);
        }
    }
}
 
int jump(int u,int c){
    if(nxt[u][c])return nxt[u][c];
    int v=u;
    while(v>1 && !trie[v][c])v=sl[v];
    if(trie[v][c])v=trie[v][c];
    return nxt[u][c]=v;
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

