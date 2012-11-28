#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define DN 505
#define MULT 2005
using namespace std;

struct drum {
    int nxt,lg,cap;
}cc;

typedef vector<drum>::iterator it;
int n,m,dst[DN];
vector<drum> gr[DN];
queue<int> c;
bitset<DN> inq;

int bf(long long cap) {
    for(int i=2; i<=n; ++i) dst[i]=MULT;
    for(c.push(1);c.size();c.pop()) {
        int fr=c.front();
        inq[fr]=0;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) {
           // cout<<i->nxt<<' '<<i->lg<<' '<<i->cap<<' '<<cap<<'\n';
            if(dst[i->nxt]>dst[fr]+i->lg && 1LL*i->cap>=cap) {
                //cout<<fr<<' '<<i->nxt<<'\n';
                dst[i->nxt]=dst[fr]+i->lg;
                if(!inq[i->nxt]) {
                    inq[i->nxt]=1;
                    c.push(i->nxt);
                }
            }
        }
    }
    if(dst[n]<=1440) return 1;
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        cin>>a>>cc.nxt>>cc.lg>>cc.cap;
        gr[a].push_back(cc);
        b=cc.nxt;
        cc.nxt=a;
        gr[b].push_back(cc);
    }
    int ls=0,ld=10000000,m;
    for(int i=1; i<=100; ++i) {
        int m=(ls+ld+1)>>1;
        if(bf(m*100LL+3000000LL)) ls=m;
        else ld=m-1;
    }
    cout<<ls;
    return 0;
}
