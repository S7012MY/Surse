#include <iostream>
#include <algorithm>
#define DN 1005
using namespace std;

int n,m,k,mt[DN][DN],x,y;
int cc[DN],rcc[DN];
int cl[DN],rcl[DN];
char o;

int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cin>>mt[i][j];
        cl[i]=rcl[i]=i;
    }
    for(int i=1; i<=m; ++i) cc[i]=rcc[i]=i;

    for(;k;--k) {
        cin>>o>>x>>y;
        if(o=='c') swap(cc[x],cc[y]);
        else if(o=='r') swap(cl[x],cl[y]);
        else cout<<mt[cl[x]][cc[y]]<<'\n';
    }
    return 0;
}
