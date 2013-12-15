#include <iostream>
#include <fstream>
#define MOD 10000
using namespace std;

int n,k,r=1;

int pt(int b,int e) {
  int r=1,x=b;
  for(;e;e>>=1) {
    if(e&1) r=(r*x)%MOD;
    x=(x*x)%MOD;
  }
  return r;
}

int main()
{
    ifstream f("multiplu2.in");
    ofstream g("multiplu2.out");
    f>>n>>k;
    int cn=n;
    for(int i=2; i*i<=cn; ++i) if(n%i==0){
      int exp=0;
      for(;n%i==0;++exp,n/=i);
      r=(r*(pt(exp+1,k)-pt(exp,k)+MOD))%MOD;
    }
    if(n>1) r=(r*(pt(2,k)-1+MOD))%MOD;
    g<<r;
    return 0;
}
