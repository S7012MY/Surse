#include <iostream>
#include <fstream>
#include <cstring>
#define MOD 666013
using namespace std;

int n,mi[3][3],rez[3][3],aux[3][3];

void inm(int a[3][3],int b[3][3],int r[3][3]) {
    for(int i=1; i<3; ++i) for(int j=1; j<3; ++j) {
        int c=0;
        for(int k=1; k<3; ++k) c=(c+1LL*a[i][k]*b[k][j])%MOD;
        r[i][j]=c;
    }
}

void lgput(int e) {
    for(int i=0; (1<<i)<=e; ++i) {
        if((1<<i)&e) {
            inm(rez,mi,aux);
            memcpy(rez,aux,sizeof(rez));
        }
        inm(mi,mi,aux);
        memcpy(mi,aux,sizeof(aux));
    }
}

int main()
{
    ifstream f("kfib.in");
    ofstream g("kfib.out");
    mi[1][2]=mi[2][2]=mi[2][1]=rez[1][1]=rez[2][2]=1;
    f>>n;
    lgput(n-1);
    g<<rez[2][2];
    return 0;
}
