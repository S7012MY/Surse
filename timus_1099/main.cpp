#include <iostream>
#include <vector>
#include <bitset>
#define DN 250
using namespace std;

typedef vector<int>::iterator it;

bitset<DN> viz;
int n,m,l[DN],r[DN];
vector<int>gr[DN];

int cup(int s) {
    if(viz[s]) return 0;
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==r[*i] || cup(*i)) {
        r[*i]=s;
        l[s]=*i;
        return 1;
    }
    return 0;
}

int main()
{
    cin>>n;
    int a,b;
    for(;cin>>a>>b;) {
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int ok=1;ok;) {
        ok=0;
        viz&=0;
        for(int i=1; i<n; ++i)
            ok|=cup(i);
    }
    int rez=0;
    for(int i=1; i<=n; ++i) if(l[i]) ++rez;
    cout<<rez/2<<'\n';
    for(int i=1; i<=n; ++i) cout<<l[i]<<' '<<i<<'\n';
    return 0;
}
