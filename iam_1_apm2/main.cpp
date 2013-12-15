#include <iostream>
#include <fstream>
#define DN 10005
using namespace std;

int mm[DN],n,m,q;

int main()
{
    ifstream f("apm2.in");
    ofstream g("apm2.out");
    f>>n>>m>>q;
    for(int i=1; i<=n; ++i) mm[i]=100000;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        mm[a]=min(mm[a],c);
        mm[b]=min(mm[b],c);
    }
    for(int i=1; i<=q;++i) {
        int a,b;
        f>>a>>b;
        g<<max(mm[a],mm[b])-1<<'\n';
    }
    return 0;
}
