#include <iostream>
#include <bitset>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
int n,m,t,viz[105][105];
const int px[]={0,1,0,-1},py[]={1,0,-1,0};
per pl,pcom;
bool check(int a, int b) {
    return(0<a && 0<b && a<=n && b<=m);
}

int main()
{
    cin>>n>>m>>pcom.x>>pcom.y>>pl.x>>pl.y>>t;
    int i=1,j=1,pc=0,dst=0;
    for(;;i+=px[pc],j+=py[pc]) {
        viz[i][j]=++dst;
        if(make_pair(i,j)==pcom) break;
        if(!check(i+px[pc],j+py[pc]) || viz[i+px[pc]][j+py[pc]]) pc=(pc+1)%4;
    }

    int pmin=max(1,viz[pl.x][pl.y]-t),pmax=min(viz[pl.x][pl.y]+t,dst);

    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) viz[i][j]=0;
    dst=pc=0;i=j=1;
    for(;;i+=px[pc],j+=py[pc]) {
        viz[i][j]=++dst;
        if(pmin<=viz[i][j] && viz[i][j]<=pmax) {
            cout<<i<<' '<<j<<'\n';
        }
        if(make_pair(i,j)==pcom) break;
        if(!check(i+px[pc],j+py[pc]) || viz[i+px[pc]][j+py[pc]]) pc=(pc+1)%4;
    }
    return 0;
}
