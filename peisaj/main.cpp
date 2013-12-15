#include <fstream>
#define DN 51
#define DK 11
using namespace std;

int n,k;
long long nr[2][DN][2],vf[2][DN][DK][2];

int main()
{
    ifstream f("peisaj.in");
    ofstream g("peisaj.out");
    nr[0][0][0]=1;
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
        nr[i&1][0][0]=nr[(i&1)^1][1][0];
        nr[i&1][0][1]=nr[(i&1)^1][1][1];
        for(int j=1; j<=n; ++j) {
            nr[i&1][j][0]=nr[(i&1)^1][j+1][0]+nr[(i&1)^1][j-1][0];
            if(j!=k) nr[i&1][j][1]=nr[(i&1)^1][j-1][1]+nr[(i&1)^1][j+1][1];
            else nr[i&1][j][1]=nr[(i&1)^1][j-1][0]+nr[(i&1)^1][j+1][1];
        }
    }
    g<<nr[n&1][0][0]<<' '<<nr[n&1][0][1]<<' ';

    vf[0][1][0][0]=1;
    for(int i=1; i<n; ++i)
        for(int j=1; j<n; ++j)
            for(int v=0; v<=k; ++v) {
                vf[i&1][j][v][0]=vf[(i&1)^1][j-1][v][0]+vf[(i&1)^1][j][v][1];
                vf[i&1][j][v][1]=vf[(i&1)^1][j+1][v][1]+vf[(i&1)^1][j][v-1][0];
            }
    g<<vf[(n-1)&1][1][k][1];
    return 0;
}
