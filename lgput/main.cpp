#include <iostream>
#include <fstream>

#define MOD 1999999973
using namespace std;

long long putere(long long x,long long p)
{
    long long aux=x,rez=1;
    for(;p;p>>=1)
    {
      if( (p&1) )
          rez=(rez*aux)%MOD;
      aux=(aux*aux)%MOD;
    }
    return rez;
}

int main()
{
    long long n,p;
    ifstream f("lgput.in");
    ofstream g("lgput.out");
    f>>n>>p;
    g<<putere(n,p);



    return 0;
}
