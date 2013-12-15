#include <fstream>
#define DN 1005
#define MOD 9901
using namespace std;

int n,nr[DN][DN],v[DN];

int main()
{
    ifstream f("culori.in");
    ofstream g("culori.out");
    f>>n;
    n*=2;
    for(int i=1; i<n;++i) {
        f>>v[i];
        nr[i][i]=1;
    }
    for(int lg=1; lg<n; ++lg) for(int i=1; i<n; ++i)
        if(v[i]==v[i+lg]) for(int k=i+1; k<i+lg; ++k)
            nr[i][i+lg]=(nr[i][i+lg]+nr[i+1][k]*nr[k+1][i+lg])%MOD;
    g<<nr[1][n-1];
    return 0;
}
