#include <iostream>
#include <fstream>
#define MOD 1000000007LL
#define LL long long
using namespace std;

LL n,p;

LL put(LL b, LL e) {
    LL r=1,x=b;
    for(;e;e>>=1) {
      if(e&1) r=(r*x)%MOD;
      x=(x*x)%MOD;
    }
    return r;
}

LL aranj(int n,int k) {
  if(k>n) return 0;
  long long r=1;
  for(int i=n; i>=(n-k+1); --i) r=(r*i)%MOD;
  return r;
}

int main () {
  ifstream f("frumoasa.in");
  ofstream g("frumoasa.out");
  f>>n>>p;
  if(p>25) g<<0;
  else {
    g<<(aranj(26,p)*put(26-p,n-p))%MOD;
  }
}
