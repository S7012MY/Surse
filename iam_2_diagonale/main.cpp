#include <iostream>
#include <fstream>
#define DN 1005
using namespace std;

int n,m[DN][DN],folp[DN*10],fols[DN*10];
long long sdp[DN*10],sds[DN*10],rez=-(1LL<<61LL);

int main()
{
    ifstream f("diagonale.in");
    ofstream g("diagonale.out");
    f>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        f>>m[i][j];
        sds[i+j]+=m[i][j];
        sdp[i-j+DN]+=m[i][j];
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        rez=max(rez,sds[i+j]);
        rez=max(rez,sdp[i-j+DN]);
    }
    g<<rez;
    return 0;
}
