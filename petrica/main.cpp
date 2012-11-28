#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;
int n,cn[DN],sumc[DN],sarb[DN][DN],ord[DN],sz;
vector<int> gr[DN];
bitset<DN> viz;

void dfs(int s) {
    viz[s]=1;
    ord[++sz]=s;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]){
        dfs(*i);
        sumc[s]+=sumc[*i];
        for(int j=1; j<=n; ++j) sarb[s][j]|=sarb[*i][j];
        sarb[s][*i]=1;
    }
    sumc[s]+=cn[s];
}

int main()
{
    ifstream f("petrica.in");
    ofstream g("petrica.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>cn[i];
    for(int i=1; i<n; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1);
    int bstdif=999999;
    for(int i=2; i<=n; ++i) for(int j=i+1; j<=n;++j) for(int k=j+1; k<=n; ++k) {
        int c1,c2,c3,c4,n1=ord[i],n2=ord[j],n3=ord[k];
        int okn2=1,okn3=1;
        c1=sumc[n1],c2=sumc[n2],c3=sumc[n3]; c4=sumc[1];
        if(sarb[n1][n2]) c1-=sumc[n2],okn2=0;
        if(sarb[n2][n3]) c2-=sumc[n3],okn3=0;
        else if(sarb[n1][n3]) c1-=sumc[n3],okn3=0;
        c4-=sumc[n1];
        if(okn2) c4-=sumc[n2];
        if(okn3) c4-=sumc[n3];
        cout<<n1<<' '<<n2<<' '<<n3<<'\n';
        cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<'\n';
        bstdif=min(bstdif,max(max(c1-c2,c4-c1),max(c2-c3,c1-c3)));
    }
    g<<bstdif;
    return 0;
}
