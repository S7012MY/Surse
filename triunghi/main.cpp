#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int n,s,m[20][20],c[20],sum,pede[1000005];

ifstream f("triunghi.in");
ofstream g("triunghi.out");

void coef() {
    for(int p=1; p<=n; ++p) {
        m[n][p]=1;
        for(int i=n-1; i; --i) {
            for(int j=1; j<=i; ++j) {
                m[i][j]=m[i+1][j]+m[i+1][j+1];
                c[p]+=m[i][j];
            }
        }
        ++c[p];
        s-=c[p];
        memset(m,0,sizeof(m));
    }
    for(int i=1; i<=n; ++i) m[n][i]=1;
}

void becate() {
    pede[0]=1;
    for(int i=1; i<=s; ++i) if(!pede[i]) {
        for(int j=1; j<=(n+1)/2; ++j) if(i-c[j]>=0 && pede[i-c[j]]) pede[i]=j;
        //cout<<i<<' '<<pede[i]<<'\n';
    }
}

int main()
{
    f>>n>>s;
    coef();
    for(int i=n-1; i; --i) for(int j=1; j<=i; ++j) m[i][j]=m[i+1][j]+m[i+1][j+1];
    becate();

    if(!pede[0]) {
        g<<"imposibil";
        return 0;
    }

    for(int i=s;i;i-=c[pede[i]]) ++m[n][pede[i]];
    for(int i=n-1; i; --i) {
        for(int j=1; j<=i; ++j) m[i][j]=m[i+1][j]+m[i+1][j+1];
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) g<<m[i][j]<<' ';
        g<<'\n';
    }
    return 0;
}
