#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <cstdlib>
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;

int n,m,start,val[DN],semn[DN],sursa;
double rez[DN];
bitset<DN> viz,isrez;
vector<per> gr[DN];

void impos() {
    cout<<"IMPOSSIBLE\n";
    exit(0);
}

void r(int s, double vl) {
    if(isrez[s] && vl!=rez[s]) impos();
    isrez[s]=1;
    rez[s]=vl;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!isrez[i->x]) r(i->x,i->y-vl);
}

void dfs(int s) {
    viz[s]=1;
   // cout<<s<<' '<<val[s]<<' '<<semn[s]<<'\n';
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(!viz[i->x]) {
            semn[i->x]=1;
            if(semn[s]==1) semn[i->x]=-1;
            val[i->x]=-val[s]+i->y;
            dfs(i->x);
        }
        else {
            if(semn[s]+semn[i->x]) {//il aflu pe x
                double sol=((double)i->y-val[s]-val[i->x])/(semn[s]+semn[i->x]);
              //  cout<<"\nx:"<<sol<<'\n';
                r(sursa,sol);
            }else {//verific validitarea
                if(val[s]+val[i->x]!=i->y) impos();
            }
        }
    }
}

int main()
{
     cin>>n>>m;
     for(int i=1; i<=m; ++i) {
         int a,b,c;
         cin>>a>>b>>c;
         gr[a].push_back(make_pair(b,c));
         gr[b].push_back(make_pair(a,c));
     }
     for(int i=1; i<=n; ++i) {
         if(!viz[i]) {
             sursa=i;
             semn[i]=1;
             dfs(i);
         }
     }
     if(isrez.count()!=n) impos();
     for(int i=1; i<=n; ++i) cout<<fixed<<setprecision(2)<<rez[i]<<'\n';
     return 0;
}
