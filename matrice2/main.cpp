#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 305
#define DQ 20005
using namespace std;

int n,q,pre[DN*DN],l,unde[DN][DN],rsp[DQ];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct query {
    int sx,sy,fx,fy,rez,ind;
} qu[DQ];

struct mat{
    int x,y,vl;
} m[DN*DN];

bool cmat(mat a, mat b) {
    return a.vl>b.vl;
}

bool cquery(query a, query b) {
    return a.rez>b.rez;
}

bool check(int ii,int jj) {
    return (ii && jj && ii<=n && jj<=n);
}

int find(int x) {
    if(pre[x]==x) return x;
    pre[x]=find(pre[x]);
    return pre[x];
}

void unite(int a,int b) {
    pre[find(a)]=find(b);
}

void baga(int i,int val) {
    for(int d=0; d<4; ++d) {
        int ii=m[i].x+dx[d],jj=m[i].y+dy[d];
        if(check(ii,jj) && m[unde[ii][jj]].vl>=val) unite(i,unde[ii][jj]);
    }
}

int main()
{
    ifstream f("matrice.in");
    ofstream g("matrice.out");
    f>>n>>q; l=n*n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        f>>m[(i-1)*n+j].vl;
        m[(i-1)*n+j].x=i;m[(i-1)*n+j].y=j;
    }
    sort(m+1,m+l+1,cmat);

    for(int i=1; i<=l; ++i) unde[m[i].x][m[i].y]=i;

    for(int i=1; i<=q; ++i) {
        f>>qu[i].sx>>qu[i].sy>>qu[i].fx>>qu[i].fy;
        qu[i].ind=i;
    }

    for(int s=(1<<20);s;s>>=1) {
        for(int i=1; i<=l; ++i) pre[i]=i;
        sort(qu+1,qu+q+1,cquery);
        int j=1;
        for(int i=1; i<=q; ++i) {
            int vc=s+qu[i].rez;
            for(;m[j].vl>=vc && j<=l;baga(j,vc),++j);
            int u1=unde[qu[i].sx][qu[i].sy],u2=unde[qu[i].fx][qu[i].fy];
            if(find(u1)==find(u2)) qu[i].rez+=s;
        }
    }
    for(int i=1; i<=q; ++i) rsp[qu[i].ind]=qu[i].rez;
    for(int i=1; i<=q; ++i) g<<rsp[i]<<'\n';
    return 0;
}
