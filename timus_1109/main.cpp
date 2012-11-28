#include <iostream>
#include <vector>
#include <bitset>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;
int n,m,k,l[DN],r[DN],rez;
vector<int> gr[DN];
bitset<DN> viz;

int cupl(int s) {
    if(viz[s]) return 0;
    viz[s]=1;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i)
        if(0==r[*i] || cupl(r[*i])) {
            l[s]=*i;r[*i]=s;
            return 1;
        }
    return 0;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=k; ++i) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
    }
    for(bool ok=1;ok;) {
        ok=0;viz&=0;
        for(int i=1; i<=n; ++i) if(0==l[i])
            ok|=cupl(i);
    }
    for(int i=1; i<=n; ++i) rez+=(0<l[i]);
    for(int i=1; i<=n; ++i) if(0==l[i]) ++rez;
    for(int i=1; i<=m; ++i) if(0==r[i]) ++rez;
    cout<<rez;
    return 0;
}
