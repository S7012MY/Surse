#include <iomanip>
#include <fstream>
#define DN 305
using namespace std;

int n,m,r,c,mc[DN][DN],sc[DN][DN],N,M,dq[DN],st,dr;
double v[DN];

bool check(int i1, int i2, double x) {
    for(int i=1; i<=m; ++i) v[i]=sc[i2][i]-sc[i1-1][i]-x*(i2-i1+1)+v[i-1];
    if(v[c]>=0) return 1;
    st=0,dr=-1;
    for(int i=c+1; i<=m; ++i) {
        for(;st<=dr && v[dq[dr]]>=v[i-c]; --dr);
        dq[++dr]=i-c;
        for(;st<dr && i-dq[st]+1>M; ++st);
        if(v[i]-v[dq[st]]>=0) return 1;
    }
    return 0;
}

int main()
{
    ifstream f("balans.in");
    ofstream g("balans.out");
    f>>n>>m>>r>>c;
    N=n; M=m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        f>>mc[i][j];
        mc[i+n][j]=mc[i][j+m]=mc[i+n][j+m]=mc[i][j];
    }
    n<<=1; m<<=1;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) sc[i][j]=sc[i-1][j]+mc[i][j];

    int rez=0;
    for(int i1=1; i1<=N; ++i1) for(int i2=i1+r-1; (i2-i1+1)<=N && i2<=n; ++i2) {
        int ls=rez,ld=(1<<30),m;
        if(!check(i1,i2,ls/1000.0)) continue;
        for(int i=1; i<=30 && ls<ld; ++i) {
            m=(ls+ld)/2;
            if(check(i1,i2,m/1000.0)) ls=m;
            else ld=m-1;
        }
        for(;check(i1,i2,ls/1000.0);++ls);
        if(!check(i1,i2,ls/1000.0)) --ls;
        rez=max(rez,ls);
    }
    g<<fixed<<setprecision(3)<<rez/1000.0;
    return 0;
}
