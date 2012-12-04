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

int main()
{
    ifstream f("matrice2.in");
    ofstream g("matrice2.out");
    f>>n>>q; l=n*n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        f>>m[(n-1)*i+j].vl;
        m[(n-1)*i+j].x=i;m[(n-1)*i+j].y=j;
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
        for(int i=1; i<=q; ++i);
    }
    return 0;
}
