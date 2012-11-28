#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#define DN 100005
using namespace std;

//bst[0][nod]=nr maxim de muchii eliminate din subarborele lui nod fara sa elimini o muchie incidenta in nod
//bst[1][nod]=nr maxim de muchii eliminate din subarborele lui nod din care am eliminat muchia care il leaga de un fiu
//bst[2][npd]=nr maxim de muchii eliminate din subarborele lui nod si lui nod i-am eliminat tatal

typedef pair<int,int> per;
typedef vector<int>::iterator it;

int n,m,bst[3][DN],fol[DN],urm[DN];
map<per, int> mc;
vector<int> gr[DN];
vector<per> rez;
set<per> ss;
bitset<DN> viz;

bool cmp(const per &a, const per&b) {
    return mc[a]<mc[b];
}

void dfs(int s) {
    viz[s]=1;
    int mc=0,ic=-1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(0==viz[*i]) {
            dfs(*i);
            bst[0][s]+=max(bst[0][*i],bst[1][*i]);
            if(bst[2][*i]>mc) {
                mc=bst[2][*i];
                ic=*i;
            }
        }
    if(-1!=ic) {
        bst[1][s]=bst[0][s]-max(bst[0][ic],bst[1][ic])+mc;
        urm[s]=ic;
    }
    bst[2][s]=bst[0][s]+1;
}

void dfss(int s) {
    viz[s]=1;
    if(urm[s] && 0==fol[s] && 0==fol[urm[s]]) {
        if(ss.find(make_pair(s,urm[s]))!=ss.end())
            rez.push_back(make_pair(s,urm[s]));
        else rez.push_back(make_pair(urm[s],s));
        fol[s]=fol[urm[s]]=1;
    }
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(0==viz[*i]) dfss(*i);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<n; ++i) {
        int a,b;
        cin>>a>>b;
        mc[make_pair(a,b)]=i;
        ss.insert(make_pair(a,b));
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1);
    viz&=0;
    dfss(1);
    sort(rez.begin(),rez.end(),cmp);
    cout<<rez.size()<<'\n';
    for(int i=0; i<rez.size(); ++i) cout<<rez[i].first<<' '<<rez[i].second<<'\n';
    return 0;
}
