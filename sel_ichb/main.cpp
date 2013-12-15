#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <cstring>
#include <cstdio>
#define BASE 100000000
#define DN 1005
using namespace std;

int n,m;
int nr[2][DN][DN];

void add(int a[DN], int b[DN]) {
    int t=0,c,i;
    for(i=1; i<=a[0] || i<=b[0] || t; ++i) {
        int cif=a[i];
        if(i>a[0]) cif=0;
        c=(t+cif+b[i])%BASE;
        t=(t+cif+b[i])/BASE;
        a[i]=c;
    }
    a[0]=i-1;
}

void cpy(int a[DN],int b[DN]) {
    for(int i=0; i<=b[0]; ++i) a[i]=b[i];
}

void print(int a[DN]) {
    if(a[0]==0 || a[0]==1 && a[0]==0) {
        cout<<0;
        return;
    }
    printf("%d",a[a[0]]);
    for(int i=a[0]-1; i; --i) printf("%.8d",a[i]);
}

int main()
{

    //cin>>n>>m;
    for(int n=1; n<=10; ++n) {
        for(int m=1; m<=10; ++m) {
            memset(nr,0,sizeof(nr));
            nr[0][0][0]=nr[0][0][1]=1;
            for(int i=1; i<=m; ++i) {
                //memset(nr[i&1],0,sizeof(nr[i&1]));
                for(int j=0; j<=n; ++j) nr[i&1][j][0]=0;
                for(int j=2; j<n; ++j) {
                    cpy(nr[i&1][j],nr[(i&1)^1][j-1]);
                    //add(nr[i&1][j],nr[(i&1)^1][j-1]);
                    add(nr[i&1][j],nr[(i&1)^1][j+1]);
                    //nr[i][j]=nr[i-1][j-1]+nr[i-1][j+1];
                }
                cpy(nr[i&1][1],nr[(i&1)^1][n]); add(nr[i&1][1],nr[(i&1)^1][2]);
                cpy(nr[i&1][n],nr[(i&1)^1][n-1]); add(nr[i&1][n],nr[(i&1)^1][1]);
                //nr[i][1]=nr[i-1][n]+nr[i-1][2];
                //nr[i][n]=nr[i-1][n-1]+nr[i-1][1];
                for(int j=1; j<=n; ++j) {
                    //nr[i][j]+=nr[i-1][0];
                    //nr[i][0]+=nr[i-1][j];
                    add(nr[i&1][j],nr[(i&1)^1][0]);
                    add(nr[i&1][0],nr[(i&1)^1][j]);
                }
            }
            print(nr[m&1][0]);
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
