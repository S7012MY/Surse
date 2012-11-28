#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

int n,m,unde[DN],a[DN],b[DN],sz,nrc,nr[2][DN],rt,cate[DN],cul[DN],ok,na,nb;;
vector<int> gr[DN],g2[DN];
bitset<DN> viz;

void dfs(int s) {
    viz[s]=1;
    ++cate[nrc];
    unde[s]=nrc;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
}

void d2(int s,int cl) {
    viz[s]=0;
    if(!cl)na+=cate[s];
    else nb+=cate[s];
    cul[s]=cl;
    for(it i=g2[s].begin();i!=g2[s].end(); ++i) {
        if(viz[*i]) {
            d2(*i,1-cl);
        }
        else if(cul[*i]!=1-cl) ok=0;
    }
    //cout<<s<<' '<<nr[0][s]<<' '<<nr[1][s]<<'\n';
}

int main()
{
    ifstream f("petrecere2.in");
    ofstream g("petrecere2.out");
    f>>n>>m;
    for(int i=0; i<m; ++i) {
        int A,B,C;
        f>>A>>B>>C;
        if(!A) {
            gr[B].push_back(C);
            gr[C].push_back(B);
        }else {
            a[++sz]=B;
            b[sz]=C;
        }
    }

    for(int i=1; i<=n; ++i) if(!viz[i]) {
        ++nrc;
        dfs(i);
    }

    for(int i=1; i<=sz; ++i) {
        g2[unde[b[i]]].push_back(unde[a[i]]);
        g2[unde[a[i]]].push_back(unde[b[i]]);
    }
    for(int i=1; i<=n; ++i) if(viz[unde[i]]) {
        ok=1;
        na=nb=0;
        d2(unde[i],0);
        if(!ok) continue;
        rt+=max(na,nb);
    }
    g<<rt;
    return 0;
}
