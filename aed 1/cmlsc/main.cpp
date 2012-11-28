#include <iostream>
#include <fstream>
#define DN 1050
using namespace std;

int n,m,a[DN],b[DN],lg[DN][DN],sol[DN],sz;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) f>>a[i];
    for(int i=1; i<=m; ++i) f>>b[i];
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(a[i]==b[j]) lg[i][j]=lg[i-1][j-1]+1;
        else lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
    for(int i=n,j=m;i>0 && j>0;)
        if(a[i]==b[j]) {
            sol[++sz]=a[i];
            --i; --j;
        }else {
            if(lg[i-1][j]>lg[i][j-1]) --i;
            else --j;
        }
    g<<sz<<'\n';
    for(int i=sz; i>0; --i) g<<sol[i]<<' ';
    return 0;
}
