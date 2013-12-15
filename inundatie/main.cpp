#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 305
using namespace std;

int n,m,q,et[DN*DN],dim,a,sp[DN*DN];

int main()
{
    ifstream f("inundatie.in");
    ofstream g("inundatie.out");
    f>>n>>m;
    for(int i=1; i<=n*m; ++i) {
        f>>a;
        if(a) et[++dim]=a;
    }
    sort(et+1,et+dim+1);
    for(int i=1; i<=dim; ++i) sp[i]=et[i]+sp[i-1];
    for(f>>q;q--;) {
        f>>a;
        if(a==0) {
            g<<"0\n";
            continue;
        }
        int p=upper_bound(et+1,et+dim+1,a-1)-et-1;
        g<<sp[p]+(dim-p)*(a-1)<<'\n';
    }
    return 0;
}
