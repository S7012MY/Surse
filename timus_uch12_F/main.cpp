#include <iostream>
#include <vector>
#include <queue>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

struct flight{
    int a,b,t1,t2;
} fl[DN];

vector<per> gr[DN];
int tp[DN];
queue<per> c;
vector<int> pre[DN],muc[DN];

int n,m,sol[DN],sz,s,ts,f,tf;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        cin>>fl[i].a>>fl[i].b>>fl[i].t1>>fl[i].t2;
        gr[fl[i].a].push_back(make_pair(fl[i].b,i));
    }
    for(int i=1; i<=n; ++i) tp[i]=(1<<30);
    cin>>s>>f>>ts>>tf;
    pre[s].push_back(0);

    for(c.push(make_pair(s,ts));c.size();c.pop()) {
        int ns=c.front().x,t=c.front().y;
       // cout<<ns<<' '<<t<<'\n';
        tp[ns]=t;
        for(it i=gr[ns].begin(); i!=gr[ns].end(); ++i) {
            int ind=i->y;
            if(t<=fl[ind].t1 && tp[i->x]>fl[ind].t2) {
                pre[i->x].push_back(ns);
                muc[i->x].push_back(ind);
                if(i->x==f && fl[ind].t2<=tf) goto sfarsit;
                c.push(make_pair(i->x,fl[ind].t2));
            }
        }
    }
    sfarsit:
    for(;pre[f][pre[f].size()-1];) {
        sol[++sz]=muc[f][muc[f].size()-1];
        int lstf=f;
        f=pre[f][pre[f].size()-1];
        pre[lstf].pop_back();
        muc[lstf].pop_back();
    }
    cout<<sz<<'\n';
    for(int i=sz; i; --i) cout<<sol[i]<<' ';
    return 0;
}
