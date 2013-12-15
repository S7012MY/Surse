/*
    se da o matrice de N pe M care reprezinta codificarea unor cabluri.
    sa se determine cate cabluri se vor intersecta dupa intinderea tuturor cablurilor
*/
#include <iostream>
#include <fstream>
#define DN 105
using namespace std;

int n,m,mt[DN][DN],start[DN],end[DN],rez[DN];

int main()
{
    ifstream f("xcabluri.in");
    ofstream g("xcabluri.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>mt[i][j];
    for(int i=1; i<=n; ++i) {
        start[mt[i][1]]=i;
        end[mt[i][m]]=i;
    }
    for(int i=1; i<=n; ++i) if(start[i])
        for(int j=1; j<=n; ++j) if(start[j]<start[i] && end[j]>end[i]) {
            ++rez[i]; ++rez[j];
        }
    for(int i=1;i<=n && start[i]; ++i) g<<rez[i]<<' ';
    return 0;
}
