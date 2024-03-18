#include<bits/stdc++.h>
using namespace std;

struct Node {
    int nxt[26];
    int cnt;
    Node() {
        fill(nxt,nxt+26,0);
        cnt=0;
    }
};

struct Trie {
    vector<Node>t;
    Trie() {
        t.push_back(Node());
    }

    void add(string s) {
        int cur = 0;
        for(auto c: s) {
            int to = c-'a';
            if(!t[cur].nxt[to]) {
                t[cur].nxt[to]=t.size();
                t.push_back(Node());
            }
            cur=t[cur].nxt[to];
        }
         t[cur].cnt++;
    }

    int get(string s) {
        int cur=0;
        for(int i=0; i<s.size(); i++) {
            int to=s[i]-'a';
            if(!t[cur].nxt[to])return 0;
            cur=t[cur].nxt[to];
        }
        return t[cur].cnt;
    }

};

void solve(){
   Trie trie;
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

