#include <iostream>
#include <fstream>
#define MOD 1000000007
using namespace std;

int n,m,a[105],sdif,nrs;
long long nr[2][100005];

int main()
{
    ifstream f("pokemon2.in");
    ofstream g("pokemon2.out");
    f>>n>>m;
    for(int i=1; i<n; ++i) {
        f>>a[i];
        sdif+=(i*a[i]);
    }
    m-=sdif;
    if(m<0) {
        g<<"0";
        return 0;
    }
    for(int i=0; i<=m; ++i) nr[1][i]=1;
    for(int g=2; g<=n; ++g) for(int c=0; c<=m; ++c) {
        nr[g&1][c]=nr[(g&1)^1][c];

        if(c-g>=0) nr[g&1][c]+=nr[g&1][c-g];

        if(nr[g&1][c]>=MOD) nr[g&1][c]-=MOD;
    }
    g<<nr[n&1][m]%MOD;
    return 0;
}
