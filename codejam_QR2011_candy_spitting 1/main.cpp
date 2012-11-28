#include <iostream>
#include <fstream>
#define DN 1005
using namespace std;

int t,n,v,sxor,sum,mi;

int main()
{
    ifstream f("input.txt");
    ofstream g("output.txt");
    f>>t;
    for(int k=1; k<=t; ++k) {
        g<<"Case #"<<k<<": ";
        f>>n;
        mi=(1<<30);
        sxor=sum=0;
        for(int i=1; i<=n; ++i) {
            f>>v;
            sxor^=v;
            sum+=v;
            mi=min(mi,v);
        }
        if(sxor) {
            g<<"NO\n";
            continue;
        }
        g<<sum-mi<<'\n';
    }
    return 0;
}
