#include <iostream>
#include <algorithm>
#define DN 505
using namespace std;

int n,k,mt[DN][DN],nr,sol[DN],sp[DN][DN],rez[DN][DN];

void makeSP(){
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
        sp[i][j]=mt[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
    for(int i=1; i<n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            rez[i][j]=sp[j-1][n]-sp[i-1][n]-sp[j-1][j-1]+sp[i-1][j-1];
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=n-i; ++j) {
            cin>>mt[i][i+j];
        }
    }
    makeSP();
    for(int i=1; i<=k; ++i) {
        int mc=0,poz=0;
        for(int i=1; i<=n; ++i) if(rez[1][i]>mc) {
            mc=rez[1][i];
            poz=i;
        }
        sol[++sol[0]]=poz;
        nr+=mc;
        for(int i=poz; i<=n; ++i) for(int j=i+1; j<=n; ++j) mt[i][j]=0;
        makeSP();
    }
    cout<<nr<<'\n';
    for(int i=1; i<=sol[0]; ++i) cout<<sol[i]<<' ';
    return 0;
}
