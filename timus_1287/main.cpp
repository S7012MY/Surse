#include <iostream>
#include <cstring>
#define DN 14005
using namespace std;

const int dx[]={-1,-1,-1,0,1,1, 1,0},
          dy[]={-1, 0, 1,1,1,0,-1,-1};
int n,b[2][8][2][DN],maxs,maxS;
char mi[DN][DN];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)cin>>mi[i][j];
    for(int i=1; i<=n; ++i) {
        for(int k=1; k<=n; ++k) for(int j=0; j<8; ++j) b[0][j][i&1][k]=b[1][j][i&1][k]=0;
        for(int j=1; j<=n; ++j) {
        for(int d=0;d<8; ++d) {
            if(mi[i][j]==mi[i+dx[d]][j+dy[d]]) {
                if(mi[i][j]=='s') b[0][d][(i&1)][j]=1+b[0][d][(i+dx[d])&1][j+dy[d]];
                else b[1][d][i&1][j]=1+b[1][d][(i+dx[d])&1][j+dy[d]];
            }else b[(mi[i][j]=='s'?0:1)][d][i&1][j]=1;
            maxs=max(b[0][d][i&1][j],maxs);
            maxS=max(b[1][d][i&1][j],maxS);
        }
    }
    }
    if(maxs>maxS) cout<<"s\n"<<maxs;
    else if(maxs==maxS) cout<<"?\n"<<maxs;
    else cout<<"S\n"<<maxS;
    return 0;
}
