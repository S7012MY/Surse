#include <iostream>
#include <fstream>
#define LL long long
#include <algorithm>
#define DN 1000005
using namespace std;

LL n,k,c[DN],q,x,y,z;
LL pmax;

int main() {
  ifstream f("beri.in");
  ofstream g("beri.out");
  f>>n>>k>>q>>x>>y>>z;
  c[1]=q;
  for(int i=2; i<=n; ++i) c[i]=(c[i-1]*x+y)%z+k;
  nth_element(c+1,c+n-k+1,c+n+1);
  for(int i=1; i<=n; ++i) if(c[i]>=c[n-k+1]) pmax+=c[i];
  pmax-=(k*(k-1))/2;
  g<<pmax;
}
