#include <iostream>
#include <fstream>
#define DN 105
using namespace std;

int n,m,rez;
char mt[DN][DN];

int main()
{
    ifstream f("cruce.in");
    ofstream g("cruce.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) f>>mt[i]+1;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        int lh=0,lv=0;
        for(;j-lh-1>0 && j+lh+1<=m && mt[i][j-lh-1]==mt[i][j+lh+1];++lh);
        for(;i-lv-1>0 && i+lv+1<=n && mt[i-lv-1][j]==mt[i+lv+1][j];++lv);
        rez+=(lv*lh);
    }
    g<<rez;
    return 0;
}
