#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

int n,m,s,cnt,v[DN];
map<string,int> mp;
string inp;
vector<int> gr[DN],ad[DN];

int first[DN],last[DN],pm[DN*2],vls[DN*2],eu[DN*2];

void lin(int s, int f) {
    first[s]=++cnt;
    pm[cnt]=1; vls[cnt]=v[s]; eu[cnt]=s;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f)
        lin(*i,s);
    last[s]=++cnt;
    pm[cnt]=-1; vls[cnt]=v[s]; eu[cnt]=s;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int x;
        cin>>inp>>x;
        if(mp.find(inp)==mp.end()) {
            mp[inp]=++cnt;
            v[i]=cnt;
        }
        v[i]=mp[inp];
        if(!x) s=i;
        else {
            gr[x].push_back(i);
            gr[i].push_back(x);
        }
    }
    cnt=0;
    lin(s,0);
    for(int i=1; i<=cnt; ++i) {
        pm[i]+=pm[i-1];
       // cout<<pm[i]<<' ';
        if(pm[i]>pm[i-1]) ad[pm[i]].push_back(eu[i]);
    }
    cin>>m;
    for(int i=1; i<=m; ++i) {
        int nod,add;
        cin>>nod>>add;
        set<int> s;
        add+=pm[nod];
        for(it i=ad[add].begin(); i!=ad[add].end(); ++i) if(first[nod]<first[*i] && first[*i]<last[nod])
            s.insert(v[*i]);
        cout<<s.size()<<'\n';
    }
    return 0;
}
