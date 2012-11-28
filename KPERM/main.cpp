#include <fstream>
#define MOD 666013
#define DN 5005
using namespace std;

int n,k,fct[DN]={1};

int main()
{
    ifstream f("kperm.in");
    ofstream g("kperm.out");
    f>>n>>k;
    if(0==(k&1)) {g<<"0\n";return 0;}
    for(int i=1; i<=n; ++i) fct[i]=(1LL*i*fct[i-1])%MOD;
    //unu roman
    int ur=1,nmk=n%k,ndk=n/k;
    for(int i=1; i<=nmk; ++i) ur=(1LL*ur*fct[ndk+1])%MOD;
    for(int i=1; i<=k-nmk; ++i) ur=(1LL*ur*fct[ndk])%MOD;
    //nr de permutari de tip unu roman
    int tp=(1LL*fct[nmk]*fct[k-nmk])%MOD;
    g<<(1LL*tp*ur)%MOD;
    return 0;
}
