#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#define DN 105
#define LL long long
using namespace std;

int t,n,m;
LL tp[2][DN],cant[2][DN],bst[DN][DN],bstc1[DN][DN],bstc2[DN][DN],rez;

inline void back(int i,int j,LL cst) {
    rez=max(rez,cst);
    if(cst<bst[i][j] && bstc1[i][j]>cant[0][i] &&bstc2[i][j]>cant[1][j]) return;
    bst[i][j]=cst;
    bstc1[i][j]=max(bstc1[i][j],cant[0][i] );
    bstc2[i][j]=max(bstc2[i][j],cant[1][j] );
    if(i>n || j>m) return;

    back(i+1,j,cst);
    back(i,j+1,cst);

    if(tp[0][i]==tp[1][j]) {
        LL cc=min(cant[0][i],cant[1][j]);
        if(cant[0][i]<cant[1][j]) {
            cant[1][j]-=cc;
            back(i+1,j,cst+cc);
            cant[1][j]+=cc;
        }
        else if(cant[0][i]==cant[1][j]) back(i+1,j+1,cst+cc);
        else {
            cant[0][i]-=cc;
            back(i,j+1,cst+cc);
            cant[0][i]+=cc;
        }
    }
}

int main()
{
    ifstream f("input");
    ofstream g("output");
    f>>t;
    for(int k=1; k<=t; ++k) {
        f>>n>>m;
        cout<<k<<'\n';
        memset(bst,0,sizeof(bst));
        memset(bstc1,0,sizeof(bstc1));
        memset(bstc2,0,sizeof(bstc2));
        for(int i=1; i<=n; ++i) f>>cant[0][i]>>tp[0][i];
        for(int i=1; i<=m; ++i) f>>cant[1][i]>>tp[1][i];
        rez=0;
        back(1,1,0);
        g<<"Case #"<<k<<": "<<rez<<'\n';
    }
    return 0;
}
