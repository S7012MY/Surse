#include <iostream>
#include <fstream>
#define DN 105
#define MOD 10007
using namespace std;

typedef int mnn[DN][DN];
int n;
mnn a,ca,rez,aux1,aux2;

void add(mnn c,mnn a, mnn b){
    //c<-a+b
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j ){
            c[i][j]=a[i][j]+b[i][j];
            if(c[i][j]>=MOD)c[i][j]-=MOD;
        }
}

void inm(mnn c, mnn a, mnn b) {
    //c<-a*b
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        int s=0;
        for(int k=0; k<n; ++k) s=(s+a[i][k]*b[k][j])%MOD;
        c[i][j]=s;
    }
}

void inc(mnn a, mnn b) {
    //adunam matricea unitate
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        a[i][j]=b[i][j];
        if(i==j) {
            ++a[i][j];
            if(a[i][j]>=MOD) a[i][j]-=MOD;
        }
    }
}

void copy(mnn a, mnn b) {
    //a=b
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) a[i][j]=b[i][j];
}

void put(mnn a, mnn s, int exp) {
    if(1>=exp) return;
    if(exp&1) {
        put(a,s,(exp-1)/2);
        inc(aux1,a);
        inm(aux2,aux1,s);
        inm(aux1,a,a);
        inm(a,aux1,ca);
        add(s,aux2,a);
    }else {
        put(a,s,exp/2);
        inc(aux1,a);
        inm(aux2,aux1,s);
        inm(aux1,a,a);
        copy(s,aux2);
        copy(a,aux1);
    }
}

int main()
{
    ifstream f("drumuri3.in");
    ofstream g("drumuri3.out");
    int m,k,q;
    f>>n>>m>>k>>q;
    for(int i=1; i<=m; ++i) {
        int x,y;
        f>>x>>y;
        --x; --y;
        a[x][y]=a[y][x]=ca[x][y]=ca[y][x]=rez[x][y]=rez[y][x]=1;
    }
    put(a,rez,k-1);
    for(int i=1; i<=q; ++i) {
        int x,y;
        f>>x>>y;
        --x; --y;
        g<<rez[x][y]<<'\n';
    }
    return 0;
}
