#include <iostream>
#include <set>
#include <algorithm>
#define DM 50005
using namespace std;

struct calator {
    int x,y,ind;
} v[DM];

bool cmp(calator a,calator b) {
    return a.y<b.y;
}

int n,m,k,p,rez[DM],sz;
multiset<int> s;
multiset<int>::iterator is;

int main()
{
    cin>>n>>m>>k>>p;
    for(int i=1; i<=k; ++i) {
        cin>>v[i].x>>v[i].y;
        v[i].ind=i;
    }
    sort(v+1,v+k+1,cmp);
    for(int i=1; i<=m; ++i) s.insert(0);
    for(int i=1; i<=k; ++i) {
        is=s.lower_bound(-v[i].x);
        if(is!=s.end()) {
            rez[++sz]=v[i].ind;
            s.erase(is);
            s.insert(-v[i].y);
        }
    }
    cout<<sz*p<<'\n';
    for(int i=1; i<=sz; ++i) cout<<rez[i]<<' ';
    return 0;
}
