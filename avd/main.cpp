#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#define x first
#define y second
#define DN 15
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int t,n,lim,state,con=1;
vector<per> gr[DN];

int grupe[DN],sz[DN];

set<vector<int> > s;

void dfs(int s,int cc) {
    grupe[s]=cc;
    ++sz[cc];
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!grupe[i->x] && !(state&(1<<i->y))) dfs(i->x,cc);
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!grupe[i->x] && (state&(1<<i->y))) dfs(i->x,++con);
}

double ntot;

void back(int sum, int last) {
    if(sum>n || sum<0) return;
    if(sum==n) {
        ++ntot;
        return;
    }
    for(int i=last; i<=n; ++i) back(sum+i,i);
}

int main()
{
    ifstream f("avd.in");
    ofstream g("avd.out");
    for(f>>t;t;--t) {
        f>>n;
        for(int i=0; i<n-1; ++i) {
            int a,b;
            f>>a>>b;
            gr[a].push_back(make_pair(b,i));
            gr[b].push_back(make_pair(a,i));
        }

        lim=(1<<(n-1));
        vector<int> c;
        for(state=0; state<lim; ++state) {
            dfs(1,1);
            for(int i=1; i<=n; ++i) if(sz[i]) c.push_back(sz[i]);
            sort(c.begin(),c.end());
            s.insert(c);

            c.clear(); for(int i=1; i<=n; ++i) grupe[i]=sz[i]=0;
            con=1;
        }
        ntot=0;
        back(0,1);
        g<<fixed<<setprecision(5)<<(double)s.size()/ntot<<'\n';
        for(int i=1; i<=n; ++i)
            gr[i].clear();
        s.clear();
    }
    return 0;
}
