#include<bits/stdc++.h>
using namespace std;

int phi(int n){
//relatively coprime 1 to n  sqrt(n)
int res=n;
for(int i=2; i*i<=n; i++){
    if(n%i==0){
        while(n%i==0)
            n/=i;
        res-=res/i;
    }
}
if(n>1)res-=res/n;
return res;
}

vector<int> phi_1_to_n(int n){
    // n*loglog(n) based on sieve
  vector<int> phi(n+1);
  for(int i=0; i<=n; i++)
    phi[i]=i;
  for(int i=2; i<=n; i++){
    if(phi[i]==i){
        for(int j=i;j<=n;j+=i)
            phi[j]-=phi[j]/i;
    }
  }
  return phi;
}

vector<int> phi_1_to_n1(int n){
    // n*log(n)
    vector<int> phi(n+1);
    phi[0]=0;phi[1]=1;

    for(int i=2; i<=n; i++)
        phi[i]=i-1;
    for(int i=2; i<=n; i++){
        for(int j=i*2;j<=n; j+=i)
            phi[j]-=phi[i];
    }
    return phi;
}

int main(){
    cout << phi(12) << '\n';
return 0;
}