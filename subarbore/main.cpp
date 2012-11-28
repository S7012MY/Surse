#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#define DN 65
#define MULT (1<<30)-1
using namespace std;

int n,m,t,st[DN],dmin[DN][DN],a[DN*DN],b[DN*DN],c[DN*DN],ind[DN*DN],sz,pre[DN],spec[DN],tc=2147483646;
vector<int> nod;

void rf() {
    for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if (i!=j && j!=k && dmin[i][k]+dmin[k][j]<dmin[i][j])
                dmin[i][j]=dmin[i][k]+dmin[k][j];
}

int find(int n) {
    if(pre[n]==n) return n;
    pre[n]=find(pre[n]);
    return pre[n];
}

void unite(int i, int j) {
    pre[find(i)]=find(j);
}

bool cmp(const int &i, const int &j) {
    return c[i]<c[j];
}

int apm(int niv) {
    sz=0;
    for(int i=1; i<=niv; ++i) for(int j=i+1; j<=niv; ++j)
        {
            a[++sz]=nod[st[i]];
            b[sz]=nod[st[j]];
            c[sz]=dmin[nod[st[i]]][nod[st[j]]];
        }
    int tcc=0;
    for(int i=0; i<=sz; ++i) ind[i]=i;
    for(int i=0; i<=n; ++i) pre[i]=i;
    sort(ind+1,ind+sz+1,cmp);
    for(int i=1; i<=sz; ++i)
        if(find(a[ind[i]])!=find(b[ind[i]])){
            tcc+=c[ind[i]];
            if(tcc>tc) return MULT;
            unite(a[ind[i]],b[ind[i]]);
        }
    return tcc;
}

void back(int niv) {//generez submultimi
    tc=min(tc,apm(niv));
    if(niv>=2*t-2) return;
    for(int i=st[niv]+1; i<=n; ++i) {
        st[niv+1]=i;
        back(niv+1);
    }
}

int main()
{
    ifstream f("subarbore.in");
    ofstream g("subarbore.out");
    f>>n>>m;
    if(m==(n*(n-1))/2) assert(0);
    memset(dmin,0x3f,sizeof(dmin));
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        dmin[a][b]=dmin[b][a]=c;
    }
    rf();

    f>>t;
    if(t==1) {
        g<<0;
        return 0;
    }
    nod.push_back(0);
    for(int i=1; i<=t; ++i) {
        int a;
        f>>a;
        spec[a]=1;
        nod.push_back(a);
        st[i]=i;
    }
    for(int i=1; i<=n; ++i) if(!spec[i]) nod.push_back(i);

    if(t>2){
        back(t);
        g<<tc;
    }else g<<dmin[nod[1]][nod[2]];
    return 0;
}
