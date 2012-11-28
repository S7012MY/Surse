#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 100005
using namespace std;

int n,v[DN],bst[DN],pre[DN],ind[DN],aib[DN],rez[DN],sz;

bool cmp(int a, int b) {
    return v[a]<v[b];
}

inline int lsb(int n) {
    return (n&(n-1))^n;
}

void ins(int i) {
    for(;i<=n; i+=lsb(i)) ++aib[i];
}

int query(int i) {
    int r=0;
    for(;i>0; i-=lsb(i)) r+=aib[i];
    return r;
}

int cb(int vl) {
    //cout<<vl<<' ';
    int pd=1;
    for(;pd<=n; pd<<=1);
    int i;
    for(i=0;pd;pd>>=1)
        if(i+pd<=n && aib[i+pd]<=vl) {
            i+=pd;
            vl-=aib[i];
            if(0==vl) return i;
        }
    return i;
}

int main()
{
    ifstream f("scmax.in");
    ofstream g("scmax.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>v[i];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    int sol=0,psol;
    for(int i=1; i<=n; ++i) {
        if(v[ind[i]]==v[ind[i-1]]) continue;
        ins(ind[i]);
        bst[i]=query(ind[i]);
        if(bst[i]>1) {
            pre[ind[i]]=cb(bst[i]-1);
            //for(;bst[pre[ind[i]]]==bst[i]-1;--pre[ind[i]]);
            ++pre[ind[i]];
        }
        if(bst[i]>sol) {
            sol=bst[i];
            psol=ind[i];
        }
        cout<<bst[i]<<' '<<ind[i]<<' '<<pre[ind[i]]<<'\n';
    }
    g<<sol<<'\n';
    //cout<<psol;
    for(;psol;rez[++sz]=v[psol],psol=pre[psol]);
    for(int i=sz; i>0; --i) g<<rez[i]<<' ';
    return 0;
}
