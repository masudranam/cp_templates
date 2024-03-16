#include<bits/stdc++.h>
using namespace std;

struct BigN{
   const int N = 1000;
   vector<int> v;
   BigN(string &s){
      int len = (int)s.size();
      for(int i = len - 1; i >= 0; i --)v.push_back(s[i] - '0');
      for(int i = len; i < N; i++)v.push_back(0);
   }
   
   BigN operator + (const BigN &other){
      BigN res = *this;
      for(int i = 0; i < N - 1; i++){
         res.v[i] += other.v[i];
         res.v[i+1] += res.v[i] / 10;
         res.v[i] %= 10;
      }
      return res;
   }

   BigN operator - (const BigN &other){
      BigN res = *this;
      for(int i = 0; i < N - 1; i++){
         res.v[i] -= other.v[i];
         while(res.v[i] < 0){
            res.v[i+1]--;
            res.v[i] += 10;
         }
      }
      return res;
   }

   BigN operator * (const BigN &other){
      string zero = "";
      BigN res(zero);
      for(int i = 0; i < N / 2; i++){
         for(int j = 0; j < N / 2; j++){
            res.v[i + j] += this-> v[i] * other.v[j];
         }
      }
      for(int i = 0; i < N - 1; i++){
         res.v[i+1] += res.v[i] / 10;
         res.v[i] %= 10;
      }
      return res;
   }

   bool operator < (const BigN &other){
      for(int i = N-1; i >= 0; i--){
         if(v[i] < other.v[i]) return true;
         if(v[i] > other.v[i]) return false;
      }
      return false;
   }

   bool operator == (const BigN &other){
      for(int i = 0; i < N; i++){
         if(v[i] != other.v[i])return false;
      }
      return true;
   }

   string toString(){
      string tmp = "";
      int cur = N - 1;
      while(cur >= 0 && v[cur] == 0)cur--;
      if(cur < 0)tmp = "0";
      else{
         for(int i = cur; i >= 0; i--){
            tmp += (char)(v[i] + '0');
         }
      }
      return tmp;
   }
};

void solve(){
   string n = "1234";
   BigN B(n);
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

