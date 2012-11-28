#include <cstdio>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,sz,rez[60],af[60][60][60];
short bst[60][60][60],prx[60][60][60],pry[60][60][60];
int dx[]={-1,-1, 0,0},
    dy[]={-1, 0,-1,0};

bool check(int a, int b,int n) {
    if(a<=0 || b<=0 || a>n || b>n) return 0;
    return 1;
}

int main()
{
    freopen("suma4.in","r",stdin);
    freopen("suma4.out","w",stdout);
    scanf("%d",&n);
    int niv=1,cit=0;
    for(;cit<n;) {
        for(int i=1; i<=niv; ++i) for(int j=1; j<=niv; ++j) {
            scanf("%d",&bst[niv][i][j]);
            af[niv][i][j]=++cit;
        }
        ++niv;
    }
    for(int l=2; l<niv; ++l)
        for(int i=1;i<=l ;++i)
            for(int j=1; j<=l; ++j) {
                int x=bst[l][i][j];
                bst[l][i][j]=(1<<14);
                for(int d=0;d<4; ++d) {
                    int ii=i+dx[d],jj=j+dy[d];
                    if(!check(ii,jj,l-1)) continue;
                    if(bst[l][i][j]>bst[l-1][ii][jj]) {
                        bst[l][i][j]=bst[l-1][ii][jj];
                        prx[l][i][j]=ii; pry[l][i][j]=jj;
                    }
                }
                bst[l][i][j]+=x;
            }
    int cmin=(1<<14),bi=-1,bj=-1;
    for(int i=1; i<niv; ++i) for(int j=1; j<niv; ++j)
        if(cmin>bst[niv-1][i][j]) {
            cmin=bst[niv-1][i][j];
            bi=i;
            bj=j;
        }
    printf("%d %d\n",niv-1,cmin);
    --niv;
    for(;niv>1;) {
        rez[++sz]=af[niv][bi][bj];
        int i=bi,j=bj;
        bi=prx[niv][i][j];
        bj=pry[niv][i][j];
        --niv;
    }
    printf("1 ");
    for(int i=sz; i>0;--i) printf("%d ",rez[i]);
    return 0;
}
