#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105, L = 20;
bool oc[N * L];

struct AC {
  int N, P;
  const int A = 10;
  vector <vector <int>> next;
  vector <int> link;
  AC(): N(0), P(0) {node();}
  void clear() {
    link.clear();
    next.clear();
    N = 0; P = 0;
    node();
  }
  int node() {
    next.emplace_back(A, 0);
    link.emplace_back(0);
    return N++;
  }
  inline int get (char c) {
    return c - '0';
  }
  int add_pattern (const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][get(c)]) next[u][get(c)] = node();
      u = next[u][get(c)];
    }
    oc[u] = true;
    return P++;
  }
  void compute() {
    queue <int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          oc[v] |= oc[link[v]];
          q.push(v);
        }
      }
    }
  }
  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }
}aho;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  return 0;
}