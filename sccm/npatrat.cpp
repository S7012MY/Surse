#include <iostream>
#include <fstream>
#define DN 80005
using namespace std;

int n,m,p1[DN],p2[DN],s1[DN],s2[DN],bst[DN],nr;

int main()
{
    ifstream f("sccm.in");
    ofstream g("sccm.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>s1[i];
        p1[s1[i]]=i;
    }
    for(int i=1; i<=m; ++i) {
        f>>s2[i];
        p2[s2[i]]=i;
    }
    nr=min(n,m);
    for(int i=nr; 0<i; --i) {
        int bs=0;
        for(int j=i+1; j<=nr; ++j) if(bst[j]>bs && p1[i]<p1[j] && p2[i]<p2[j]) bs=bst[j];
        bst[i]=bs+1;
    }
    int r=0;
    for(int i=1; i<=nr; ++i) r=max(r,bst[i]);
    g<<r;
    //cout<<r;
    return 0;
}
