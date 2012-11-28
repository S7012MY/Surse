#include <fstream>
using namespace std;

int n,v[1000005],fr[1000005],i,j;

int main()
{
    ifstream f("mincinosi.in");
    ofstream g("mincinosi.out");
    for(f>>n,i=1; i<=n; ++i) f>>v[i],++fr[v[i]];
    for(i=0; i<=n; ++i) if(fr[i]==n-i) break;
    g<<fr[i]<<'\n';
    for(j=1; j<=n; ++j) if(v[j]==i) g<<j<<' ';
    return 0;
}
