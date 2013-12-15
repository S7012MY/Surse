#include <fstream>
#define DN 1000005
using namespace std;

int n,v[DN],nr,k;

int main()
{
    ifstream f("elmaj.in");
    ofstream g("elmaj.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>v[i];
    for(int i=1; i<=n; ++i) {
        if(0==k) nr=v[i];
        if(v[i]==nr) ++k;
        else --k;
    }
    if(0==k) g<<"-1";
    k=0;
    for(int i=1; i<=n; ++i) if(nr==v[i]) ++k;
    g<<nr<<' '<<k;
    return 0;
}
