#include <cstdio>
#include <vector>
#include <set>
#define DN 305
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
typedef multiset<int>::iterator is;

int n,m,k,bst;
vector<per> gr[DN];
multiset<int> mmin,mmax;

void dfs(int s,int smin,int smax) {
    bst=max(bst,smin-smax);
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        int fiu=i->x,cst=i->y,ok1=0,ok2=0,ermin,ermax;
        if(mmin.size()<k) {
            mmin.insert(cst);mmax.insert(-cst);
            smin+=cst;smax+=cst;
            dfs(fiu,smin,smax);
            smin-=cst; smax-=cst;
            mmin.erase(cst); mmax.erase(cst);
            continue;
        }
        if(mmin.lower_bound(cst)!=mmin.end()) {
            is s=mmin.end(); --s;
            ermin=*s;
            s=mmin.find(ermin);
            mmin.erase(s); smin-=ermin;
            ok1=1;
            smin+=cst;
            mmin.insert(cst);
        }
        if(mmax.lower_bound(-cst)!=mmin.end()) {
            is s=mmax.end();
            --s;
            ermax=*s;
            s=mmax.find(ermax);
            mmax.erase(s); smax+=ermax;
            ok2=1;
            smax+=cst;
            mmax.insert(-cst);
        }
        dfs(fiu,smin,smax);
        if(ok1) {
            is s=mmin.find(cst);
            mmin.erase(s);
            mmin.insert(ermin);
            smin-=cst;
        }
        if(ok2) {
            is s=mmax.find(-cst);
            mmax.erase(s);
            mmax.insert(ermax);
            smax-=cst;
        }
    }
}

int main()
{
    freopen("kgraf.in","r",stdin);
    freopen("kgraf.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        gr[a].push_back(make_pair(b,c));
    }
    for(int i=1; i<=n; ++i) dfs(i,0,0);
    printf("%d",bst);
    return 0;
}
