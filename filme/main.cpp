#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 10005
using namespace std;

int n,m,g[DN];

int main()
{
    ifstream f("filme.in");
    ofstream go("filme.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        int a,b;
        f>>a>>b;
        g[i]=a+b;
    }
    sort(g+1,g+n+1);
    int dc=0,rez=0;
    for(int i=1; i<=n; ++i) if(dc+g[i]<=m) {
        ++rez;
        dc+=g[i];
    }
    go<<rez;
    return 0;
}
