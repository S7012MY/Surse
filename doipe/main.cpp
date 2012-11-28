#include <fstream>
#define DN 2005
#define MOD 29997
using namespace std;

char rel[DN];
int nr[3][DN],t,n;

int main()
{
    ifstream f("doipe.in");
    ofstream g("doipe.out");
    for(f>>t;t;--t) {
        f>>n>>rel+1;
        nr[1][1]=1;
        for(int i=2; i<=n; ++i) {
            int lc=i&1,lp=(i&1)^1;
            for(int j=1; j<=i; ++j) {
                nr[lc][j]=0;
                if(rel[i-1]=='<')
                    nr[lc][j]+=nr[lp][j-1];
                else
                    nr[lc][j]+=(nr[lp][i-1]-nr[lp][j-1]+MOD);
                if(nr[lc][j]>=MOD) nr[lc][j]-=MOD;
                nr[lc][j]+=nr[lc][j-1];
                if(nr[lc][j]>=MOD) nr[lc][j]-=MOD;
            }
        }
        g<<nr[n&1][n]<<'\n';
    }
    return 0;
}
