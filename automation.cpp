#include<bits/stdc++.h>
using namespace std;

const int N = 105, M = 11, mod = 1e9 + 7;
vector<int> prefix_function(string &s) {
  int n = (int)s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j]) j = pi[j-1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int aut[N][26];
void compute_automaton(string s) {
  s += '#';
  int n = (int)s.size();
  vector<int> pi = prefix_function(s);
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i]) aut[i][c] = aut[pi[i-1]][c];
      else aut[i][c] = i + ('a' + c == s[i]);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}