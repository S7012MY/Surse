#include <cstdio>
#include <set>
#include <algorithm>
#include <bitset>
#define BM 1005
using namespace std;
typedef pair<int,int> per;

set <per>s;
int dx[]={-1,0,0,1},dy[]={0,1,-1,0},n,m,mat[BM][BM],rez[BM][BM],solx,soly,sol=-1,cnt;
bitset <BM> viz[BM];
int check(int i,int j){
    if(i<1||j<1||i>n||j>m)return 0;
    return 1;
}

void cacat(int i,int j){
    int d;
    ++cnt;
    viz[i][j]=1;
    for(d=0;d<4;++d){
        int ii=dx[d]+i,jj=dy[d]+j;
        if(check(ii,jj)&&viz[ii][jj]==0&&mat[ii][jj]==2){
            cacat(ii,jj);
        }
        if(check(ii,jj)&&mat[ii][jj]==0)s.insert(make_pair(ii,jj));
    }
}
int main () {
    int i,j;
    freopen("go.in","r",stdin);
    freopen("go.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&mat[i][j]);
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(viz[i][j]==0&&mat[i][j]==2){
        cnt=0;
        cacat(i,j);
        if(s.size()==1){
            per fr=*s.begin();
            rez[fr.first][fr.second]+=cnt;
        }
        s.clear();
    }
    for(i=1;i<=n;++i)for(j=1;j<=m;++j){
        if(mat[i][j]==0&&rez[i][j]>sol){
            sol=rez[i][j];
            solx=i;
            soly=j;
        }
    }
    printf("%d %d",solx-1,soly-1);
    return 0;
}
