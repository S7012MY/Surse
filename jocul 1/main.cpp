#include <iostream>
#include <fstream>
#define DN  200005
#define ADD 100000
using namespace std;

int n,pot[2][DN],sa[2][DN],sb[2][DN],ls,ld,nls,nld;

int main()
{
    ifstream f("jocul.in");
    ofstream g("jocul.out");
    pot[0][ADD]=1;
    f>>n;
    for(int i=1; i<=n; ++i) {
        int ob,act=i&1,pre=(i&1)^1;
        f>>ob;
        nls=999999,nld=0;
        for(int j=ls; j<=ld; ++j) if(pot[pre][j+ADD]) {
            pot[act][j+ob+ADD]=pot[act][j-ob+ADD]=1;
            sa[act][j+ob+ADD]=ob+sa[pre][j+ADD];
            sb[act][j+ob+ADD]=sb[pre][j+ADD];

            sb[act][j-ob+ADD]=ob+sb[pre][j+ADD];
            sa[act][j-ob+ADD]=sa[pre][j+ADD];

            pot[pre][j+ADD]=sa[pre][j+ADD]=sb[pre][j+ADD]=0;
            nls=min(nls,j-ob);
            nld=max(nld,j+ob);
        }
        ls=nls;
        ld=nld;
    }
    for(int j=0; j<=ADD; ++j) if(pot[n&1][j+ADD]) {
        g<<sb[n&1][j+ADD]<<' '<<sa[n&1][j+ADD];
        break;
    }
    return 0;
}
