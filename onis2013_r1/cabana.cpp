//(k!)^(n/k) * (k! / (k-n%k)!)
#include <fstream>
#include <iostream>
#define LL long long
#define MOD 1000000007
using namespace std;

int t;
LL n,k;
int fct[1000005];

LL put(LL b, LL e) {
    LL r=1,x=b;
    for(;e;e>>=1) {
      if(e&1) r=(r*x)%MOD;
      x=(x*x)%MOD;
    }
    return r;
}

LL invmod(LL nr) {
  return put(nr,MOD-2);
}

int main() {
  ifstream f("cabana.in");
  ofstream g("cabana.out");
  fct[0]=fct[1]=1;
  for(int i=2; i<=1000000; ++i) fct[i]=(fct[i-1]*1LL*i)%MOD;
 // cout<<sizeof(fct)/1000;
  for(f>>t;t--;) {
    f>>n>>k;
    LL r=1;
    r=put(fct[k],n/k);
    //cout<<r<<'\n';
    if(n%k) {
      r=(r*fct[k])%MOD;
      r=(r*invmod(fct[k-n%k]))%MOD;
    }
    g<<r<<'\n';
  }
}
