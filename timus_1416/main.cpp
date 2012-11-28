#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#define DM 505
#define DN 505*505
using namespace std;

typedef vector<int>::iterator it;

int n,m,fol[DN],a[DN],b[DN],cst[DN],ind[DN],pre[DM];
vector<int> sol,gr[DM];
bitset<DM> viz;

bool cmp(const int &i, const int &j) {
    return cst[i]<cst[j];
}

int find(int n) {
    if(pre[n]==n) return n;
    pre[n]=find(pre[n]);
    return pre[n];
}

void unite(int i, int j) {
    pre[find(i)]=find(j);
}

int apm(int ok) {
    for(int i=1; i<=n; ++i) pre[i]=i;
    int tc=0,lst,nrc=0;
    for(int i=1; i<=m; ++i)
        if(find(a[ind[i]])!=find(b[ind[i]]) && !fol[i]) {
            tc+=cst[ind[i]];
            unite(a[ind[i]],b[ind[i]]);
            lst=i;
            if(ok) sol.push_back(i);
            ++nrc;
        }
    if(nrc!=n-1) return -1;
    return tc;
}

void dfs(int s,int p) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(0==viz[*i] && (s!=a[ind[p]] || *i!=b[ind[p]]) && (s!=b[ind[p]] || *i!=a[ind[p]]))
            dfs(*i,p);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        cin>>a[i]>>b[i]>>cst[i];
        gr[a[i]].push_back(b[i]);
        gr[b[i]].push_back(a[i]);
        ind[i]=i;
    }
    int fapm;
    sort(ind+1,ind+m+1,cmp);
    fapm=apm(1);
    cout<<"Cost: "<<fapm;

    int bapm=(1<<30);
    for(int i=sol.size()-1; i>=0; --i) {
        viz&=0;
        dfs(1,sol[i]);
        if(viz.count()==n) {
            fol[sol[i]]=1;
            bapm=min(bapm,apm(0));
            fol[sol[i]]=0;
          //  break;
        }
        if(fapm==bapm) break;
        if(i==0 && bapm==(1<<30)) {
            cout<<"\nCost: -1";
            return 0;
        }
    }

    cout<<"\nCost: "<<bapm;
    return 0;
}
