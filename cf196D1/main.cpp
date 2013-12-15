#include <iostream>
#define LL long long
#define MOD 1000000009LL
using namespace std;

LL n,m,k;

LL put(int b, int e) {
    LL r=1,x=b;
    for(;e;e>>=1) {
      if(e&1) r=(r*x)%MOD;
      x=(x*x)%MOD;
    }
    return r;
}

int main()
{
    cin>>n>>m>>k;
    LL x=max(m-(n-n/k),0LL);
    LL rez=(put(2,x+1)-2+MOD)%MOD;
    rez=(rez*k)%MOD;
    rez=((rez+m)%MOD-(x*k)%MOD+MOD)%MOD;
    cout<<rez;
    return 0;
}
