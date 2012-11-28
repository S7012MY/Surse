#include <iostream>
#include <fstream>
#define DN 1000005
using namespace std;

int n,m,sp[DN],x;

int main()
{
    ifstream f("distincte2.in");
    ofstream g("distincte2.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>x;
        if(!sp[x])++sp[x];
        }
    for(int i=1; i<DN; ++i) sp[i]+=sp[i-1];
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        g<<sp[b]-sp[a-1]<<'\n';
    }
    return 0;
}
