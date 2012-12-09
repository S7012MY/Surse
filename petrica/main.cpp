#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstring>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n,p[DN],nr[4],cnt,n1,n2,dmin=(1<<30),nrf[DN];
vector<int> gr[DN];
bitset<DN> viz;

void dfs(int s,int f) {
    if(n1==s || n2==s) ++cnt;
    if(cnt) viz[s]=1;
    nr[cnt]+=p[s];
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(*i!=f) dfs(*i,s);
    if(n1==s || n2==s) --cnt;
}

void rez(int s,int f) {
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f && !viz[*i]) {
        dfs(*i,s);
        nrf[s]+=nrf[*i];
    }
    nrf[s]+=p[s];
    int mi=min(min(nr[1],nr[2]),min(nr[0]-nrf[s],nrf[s]));
    int ma=max(max(nr[1],nr[2]),max(nr[0]-nrf[s],nrf[s]));
    dmin=min(dmin,ma-mi);
}

int main()
{
    ifstream f("petrica.in");
    ofstream g("petrica.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>p[i];
    for(int i=1; i<n; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(n1=1; n1<n; ++n1) for(n2=n1+1; n2<=n; ++n2) {
        viz&=0;
        memset(nrf,0,sizeof(nrf));
        nr[0]=nr[1]=nr[2]=nr[3]=0;
        cnt=0;
        dfs(1,0);
        cout<<n1<<' '<<n2<<' '<<nr[1]<<' '<<nr[2]<<'\n';
        rez(1,0);
    }
    g<<dmin;
    return 0;
}
