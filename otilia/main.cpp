#include <iostream>
#include <fstream>
#define DN 500005
using namespace std;

int mk[10][DN],st[DN],sz,m,n,k,p;

int main()
{
    ifstream f("otilia.in");
    ofstream g("otilia.out");
    for(int p=1; p<11; ++p) {
      mk[p][1]=(1<<30);
      sz=1;
      st[1]=1;
      for(int i=2; i<DN; ++i) {
        for(;sz; --sz)
          if(mk[p][st[sz]]>p*(i-st[sz])) {
            mk[p][i]=i-st[sz];
            break;
          }
        for(;mk[p][st[sz]]<=mk[p][i];--sz);
        st[++sz]=i;
      }
    }
    for(f>>m;m;--m) {
      f>>n>>k>>p;
      if(mk[p][n]<=k) g<<1;
      else g<<0;
      g<<'\n';
    }
    return 0;
}
