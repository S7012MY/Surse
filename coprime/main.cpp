#include <iostream>
#include <fstream>
#include <bitset>
#define DN 55
using namespace std;

int n,m,cnt,pr[10000],szp;
bitset<DN> ma[DN];
bitset<2000000> isp;

ifstream f("coprime.in");
ofstream g("coprime.out");

typedef int Huge[1001];

Huge rez[DN];

void c() {
    for(int i=2; i<=10000; ++i) if(0==isp[i]) {
        pr[++szp]=i;
        for(int j=i+i; j<=10000; j+=i) isp[j]=1;
    }
}

void WriteHuge(Huge X)
{
  int i;
  for (i=X[0]; i; i--)
     g<<X[i];
  g<<"\n";
}

void Mult(Huge H, unsigned long X)
/* H <- H*X */
{ int i;
  unsigned long T=0;

  for (i=1;i<=H[0];i++)
    { H[i]=H[i]*X+T;
      T=H[i]/10;
      H[i]=H[i]%10;
    }
  while (T) /* Cat timp exista transport */
    { H[++H[0]]=T%10;
      T/=10;
    }
}

int main()
{
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int x,y;
        f>>x>>y;
        ma[x][y]=ma[y][x]=1;
    }
    c();
    for(int i=1; i<=n; ++i) rez[i][0]=rez[i][1]=1;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(0==ma[i][j]) {
        Mult(rez[i],pr[++cnt]);
        Mult(rez[j],pr[cnt]);
    }
    for(int i=1; i<=n; ++i) WriteHuge(rez[i]);
    return 0;
}
