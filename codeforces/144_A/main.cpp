#include <iostream>
#include <fstream>
#define DN 105
#define DK 100005
using namespace std;

int K,k,n,cmb[DN][4],bst;
char rez[DN][DN];

int main()
{
    cin>>k;
    K=k;
    cmb[0][0]=1;
    for(int i=1; i<=100; ++i) {
        cmb[i][0]=1;
        for(int j=1; j<=3; ++j) {
            cmb[i][j]=cmb[i-1][j-1]+cmb[i-1][j];
            //cout<<cmb[i][j]<<' ';
        }
        if(cmb[i][3]<=K) bst=i;
       //cout<<'\n';
    }
    n=bst;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(i!=j) rez[i][j]='1';
        else rez[i][j]='0';
    k-=cmb[bst][3];
    int nc=n;
    for(;k>0;) {
        ++nc;
        rez[nc][1]=rez[1][nc]='1';
        rez[nc][2]=rez[2][nc]='1';
        for(int i=3; i<=nc; ++i) rez[i][nc]=rez[nc][i]='0';
        --k;
        for(int i=3; k-i+1>0; k-=(i-1),++i) rez[i][nc]=rez[nc][i]='1';
    }
    cout<<nc<<'\n';
    for(int i=1; i<=nc; ++i) {
        cout<<rez[i]+1<<'\n';
    }

    return 0;
}
