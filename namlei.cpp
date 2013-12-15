#include <fstream>
#include <cstring>
#include <iostream>
#define DN 30005
#define DK 9
using namespace std;

short ai[4*DN][DK][DK],m[DN][DK][DK],rez[DK][DK],crez[DK][DK];
int n,x,y,p,K,mod[1000000],cnt,k,i,j;

void inm(short A[][DK], short B[][DK],short C[][DK]) {
	memset(C, 0, sizeof(m[0]));
	for(int j=0; j<K; ++j) for(int i=0; i<K; ++i)
        for(int k=0; k<K; ++k) C[i][k]=mod[C[i][k]+A[i][j]*B[j][k]];
}

void update(int vn, int ls, int ld) {
    if(ls==ld) {
        for(int i=0; i<K; ++i) for(int j=0; j<K; ++j) ai[vn][i][j]=1;
        int pj,pk;
        for(int w=1; w<=cnt; ++w) {
            ++ai[vn][j][k];
            pj=j,pk=k;
            j=(pj*x+pk*w*y+1)%K;
            k=(pj*w*x+pk*y+1)%K;
        }
        return;
    }
    int fs=vn<<1,m=(ls+ld)>>1;
    if(i<=m) update(fs,ls,m);
    else update(fs+1,m+1,ld);
    inm(ai[fs],ai[fs+1],ai[vn]);
}

int gls,gld;

void query(int vn, int ls, int ld) {
    if(gls<=ls && ld<=gld) {
        inm(rez,ai[vn],crez);
        memcpy(rez,crez,sizeof(crez));
        return;
    }
    int m=(ls+ld)>>1,fs=(vn<<1);
    if(gls<=m) query(fs,ls,m);
    if(gld>m) query(fs+1,m+1,ld);
}

void build(int vn, int ls, int ld) {
    if(ls==ld) {
        memcpy(ai[vn],m[ls],sizeof(m[ls]));
        return;
    }
    int m=(ls+ld)>>1,fs=(vn<<1);
    build(fs,ls,m);
    build(fs+1,m+1,ld);
    inm(ai[fs],ai[fs+1],ai[vn]);
}

int main()
{
    ifstream f("namlei.in");
    ofstream g("namlei.out");
    for(i=1; i<1000000; ++i) {
        mod[i]=mod[i-1]+1;
        if(mod[i]>=997) mod[i]-=997;
    }
    f>>n>>K>>x>>y;
    for(i=0; i<n; ++i) {
        f>>cnt>>j>>k;
        for(int l=0; l<K; ++l) for(int n=0; n<K; ++n) m[i][l][n]=1;
        int pj,pk;
        for(int w=1; w<=cnt; ++w) {
            ++m[i][j][k];
            pj=j,pk=k;
            j=(pj*x+pk*w*y)%K;
            k=(pj*w*x+pk*y)%K;
        }
    }
    build(1,0,n-1);
    char c;
    for(;0==f.eof();) {
        f>>c;
        if(f.good()) {
        if('Q'==c) {
            int X,Y;
            f>>i>>X>>j>>Y;
            gls=i; gld=j-1;
            memset(rez,0,sizeof(rez));
            for(int l=0; l<K; ++l) rez[l][l]=1;
            query(1,0,n-1);
            cout<<rez[X][Y]<<'\n';
            g<<rez[X][Y]<<'\n';
        }else {
            f>>i>>cnt>>j>>k;
            update(1,0,n-1);
        }
        }
    }
    return 0;
}
