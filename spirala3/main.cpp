#include <fstream>
#include <cstring>
using namespace std;

short n,m,xc,yc,mi[55][55],dirl[4][55][55],pede[4][55][55][55][55],aux[55][55];
int rez;

void idir() {
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(mi[i][j]!=1) dirl[0][i][j]=dirl[0][i][j-1]+1;
    for(int i=1; i<=n; ++i) for(int j=m; j;--j)
        if(mi[i][j]!=1) dirl[2][i][j]=dirl[2][i][j+1]+1;
    for(int i=n; i; --i) for(int j=1; j<=m; ++j)
        if(mi[i][j]!=1) dirl[1][i][j]=dirl[1][i+1][j]+1;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(mi[i][j]!=1) dirl[3][i][j]=dirl[3][i-1][j]+1;
}

void ipd() {
    for(int k=0; k<4; ++k) for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(!mi[i][j]) pede[k][i][j][i][j]=1;
}

void muta(short &x, short &y, short &x2, short &y2, short dir) {
    if(dir==0) --y;
    else if(dir==1) ++x2;
    else if(dir==2) ++y2;
    else --x;
}

void get(short x, short y, short x2, short y2, short dir) {
    if(dir==0) {xc=x,yc=y;}
    else if(dir==1) {xc=x2,yc=y;}
    else if(dir==2) {xc=x2,yc=y2;}
    else {xc=x,yc=y2;}
}

short dist(short x, short y, short x2, short y2, short dir) {
    if(dir==0 || dir==2) return y2-y+1;
    else if(dir==1 || dir==3) return x2-x+1;
}

void calc() {
    short x1,y1,x2,y2;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        for(int x=1; x+i<=n; ++x) for(int y=1; y+j<=m; ++y) for(int d=0; d<4; ++d) {
            x1=x; y1=y; x2=x+i; y2=y+j;
            if(pede[d][x1][y1][x2][y2]>0) {
                muta(x1,y1,x2,y2,d);
                get(x1,y1,x2,y2,d);
                if(!mi[xc][yc]) {
                    pede[d][x1][y1][x2][y2]=max((int)pede[d][x1][y1][x2][y2],pede[d][x][y][x+i][y+j]+1);
                    int nxd=(d+1)%4;
                    rez=max(rez,pede[d][x][y][x+i][y+j]+dirl[nxd][xc][yc]);
                    if(dirl[nxd][xc][yc]>=dist(x1,y1,x2,y2,nxd))
                        pede[nxd][x1][y1][x2][y2]=max((int)pede[nxd][x1][y1][x2][y2],pede[d][x][y][x+i][y+j]+dist(x1,y1,x2,y2,nxd));
                }
            }
        }
}

void r() {
    for(int i=0; i<=n+1; ++i) for(int j=0; j<=m+1; ++j)
        aux[i][j]=mi[i][m-j+1];
    memcpy(mi,aux,sizeof(mi));
    memset(pede,0,sizeof(pede));
    memset(dirl,0,sizeof(dirl));
}

int main() {
    ifstream f("spirala3.in");
    ofstream g("spirala3.out");
    f>>n>>m;
    for(int i=0; i<=n+1; ++i) for(int j=0; j<=m+1; ++j)
        if(i && i<=n && j<=m) f>>mi[i][j];
        else mi[i][j]=1;

    idir();ipd();

    calc();
    r();idir(); ipd();
    calc();
    g<<rez;
    return 0;
}
