#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define DN 4005
#define x first
#define y second
using namespace std;

typedef pair<int,int> PII;
int n,sol[DN];

PII v[DN];
vector<PII> sf;

struct per {
    int x,y,ind;
}pss[DN];

class cmp {
    public:
    bool operator () (const per &a, const per &b) {
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }
};

bool c(const per &a,const per &b) {
    return a.x<b.x;
}

set<per,cmp> s;

int main() {
    ifstream f("motel.in");
    ofstream g("motel.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        per z;
        f>>z.x>>z.y;
        z.ind=i;
        pss[i]=z;
    }
    for(int i=1; i<=n; ++i) {
        f>>v[i].x;
        v[i].y=i;
    }
    sort(v+1,v+n+1);
    sort(pss+1,pss+n+1,c);
    int ip=1;
    for(int i=1; i<=n; ++i) {
        per el;
        for(;pss[ip].x<=v[i].x && pss[ip].y>=v[i].x;++ip) {
            s.insert(pss[ip]);
        }
        for(;s.size() && s.begin()->y<v[i].x;s.erase(s.begin()));
        el.x=-1000; el.y=v[i].x;
        set<per,cmp>::iterator is;
        is=s.lower_bound(el);
        if(is==s.end()) {
            g<<"0 0";
            return 0;
        }
        sf.push_back(make_pair(is->ind,v[i].y));
        s.erase(is);
    }
    for(int i=0; i<sf.size(); ++i) g<<sf[i].x<<' '<<sf[i].y<<'\n';
    return 0;
}
