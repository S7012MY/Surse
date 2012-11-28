#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN],st,dr;
int n,m,e,l[DN],r[DN],nrc,a,b,dist[DN];
bitset<DN> viz;
set<pair<int,int> >s;

int cupleaza(int s) {
    if(viz[s]) return 0;
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==r[*i]||cupleaza(r[*i])) {
        l[s]=*i; r[*i]=s;
        return 1;
    }
    return 0;
}

void dfs(int s, int f) {
    dist[s]=dist[f]+1;
    if(dist[s]&1) st.push_back(s);
    else dr.push_back(s);
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(f!=*i) dfs(*i,s);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        cin>>a>>b;
        s.insert(make_pair(a,b));
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,0);
   // for(int i=0; i<st.size(); ++i) cout<<st[i]<<' ';
    for(bool ok=1; ok;) {
        ok=0; viz&=0;
        for(int i=0; i<st.size(); ++i) if(0==l[st[i]]) ok|=cupleaza(st[i]);
        //for(int i=1; i<=n; ++i) if(0==l[st[i]]) ok|=cupleaza(i);
    }
    for(int i=0; i<st.size(); ++i) nrc+=(0<l[st[i]]);
    //for(int i=1; i<=n; ++i) nrc+=(0<l[i]);
    cout<<nrc<<'\n';
    for(int i=1; i<=n; ++i) if(l[i])
        if(s.find(make_pair(i,l[i]))!=s.end()) cout<<i<<' '<<l[i]<<'\n';
        else cout<<l[i]<<' '<<i<<'\n';
}
