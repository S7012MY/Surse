#include <cstdio>
#include <queue>
#include <algorithm>
#include <bitset>
#define BM 105
using namespace std;

typedef pair<int,int> per;
queue <per>c;
int dx[]={-1,0,0,1},dy[]={0,1,-1,0};
int drum[BM][BM],n,m,cont[4];
char mat[BM][BM];
bitset <BM> viz[BM];

int check(int i,int j){
    if(i<1||j<1||i>n||j>m)return 0;
    return 1;
}
int vecin (int i,int j,char cacat){
    int d;
    for(d=0;d<4;++d)if(check(i+dx[d],j+dy[d])&&mat[i+dx[d]][j+dy[d]]==cacat)return 1;
    return 0;
}
void frumos(int i,int j){
    int d;
    viz[i][j]=1;
    for(d=0;d<4;++d)if(check(i+dx[d],j+dy[d])&&viz[i+dx[d]][j+dy[d]]==0){
        int ii=i+dx[d],jj=j+dy[d];
         if(mat[ii][jj]==mat[i][j])frumos(ii,jj);
    }

}
int main(){
    int i,j,d,minim=999999;
    freopen("insule.in","r",stdin);
    freopen("insule.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;++i)fgets(mat[i]+1,BM,stdin);
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(mat[i][j]=='1')c.push(make_pair(i,j));
    for(;c.size();c.pop()){
        per fr=c.front();
        for(d=0;d<4;++d){
            int ii=dx[d]+fr.first,jj=dy[d]+fr.second;
            if(check(ii,jj)&&mat[ii][jj]=='0'&&viz[ii][jj]==0){
                viz[ii][jj]=1;
                drum[ii][jj]=drum[fr.first][fr.second]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
   /* for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)fprintf(stderr,"%d ",drum[i][j]);
        fprintf(stderr,"\n");
    }*/
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(drum[i][j]!=0&&drum[i][j]<minim&&vecin(i,j,'2'))minim=drum[i][j];
    for(i=1;i<=n;++i)viz[i]&=0;
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(viz[i][j]==0&&mat[i][j]!='0'){
        frumos(i,j);
        ++cont[mat[i][j]-'0'];
    }
    for(i=1;i<4;++i)printf("%d ",cont[i]);
    printf("%d",minim);
    return 0;

}
