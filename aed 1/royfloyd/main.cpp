#include <iostream>
#include <fstream>
#define DN 105
#define MULT (1<<29)
using namespace std;

int n,dmin[DN][DN];

int main()
{
    ifstream f("royfloyd.in");
    ofstream g("royfloyd.out");
    f>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        f>>dmin[i][j];
        if(0==dmin[i][j]) dmin[i][j]=MULT;
    }
    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) if(i!=k)
        for(int j=1; j<=n; ++j) if(j!=k && j!=i) dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[k][j]);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j)
            if(dmin[i][j]==MULT) g<<"0 ";
            else g<<dmin[i][j]<<' ';
        g<<'\n';
    }
    return 0;
}
