#include <iostream>
#include <fstream>
#define DN 1005
#define MOD 9973
using namespace std;

int n,k,nr[DN][DN],r[DN];

int main()
{
    ifstream f("stiva2.in");
    ofstream g("stiva2.out");
    f>>n>>k;
    nr[1][1]=2;
    for(int i=2; i<=k+1; ++i) for(int j=0; j<=k; ++j) {
        nr[i][j]=nr[i-1][j+1];
        if(j>1) nr[i][j]+=nr[i-1][j-1];
        if(nr[i][j]>=MOD) nr[i][j]-=MOD;
    }
    r[0]=1;
    for(int i=2; i<=n; i+=2)
        for(int lg=2; lg<=k+1 && lg<=i; lg+=2)
            r[i]=(r[i]+r[i-lg]*nr[lg][0])%MOD;
    g<<r[n];
    return 0;
}
