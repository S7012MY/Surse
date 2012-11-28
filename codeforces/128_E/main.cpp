#include <iostream>
#include <set>
#define DN 100005
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef set<per>::iterator is;
typedef set<per,greater<per> >::iterator ig;

set<per > s;
set<per,greater<per> > cd,pot;

struct rob {
    int ci,fi,li;
} v[DN];

int n,d,S,ct;
int nrob,ft;

int main()
{
    cin>>n>>d>>S;
    for(int i=1; i<=n; ++i) {
        cin>>v[i].ci>>v[i].fi>>v[i].li;
        if(v[i].li>=d) s.insert(mp(v[i].fi,i));
        if(v[i].li<d || v[i].fi>S) cd.insert(mp(v[i].ci,i));
        else pot.insert(mp(v[i].ci,i));
    }
    for(is i=s.begin(); i!=s.end();) {
        int fi=i->x,ind=i->y;
        if(fi<=S && v[ind].ci) {
            ++nrob;
            ct+=v[ind].ci;
            ft+=fi;

            S-=fi;
            i=s.end();
            s.erase(s.find(mp(fi,ind)));
            if(cd.find(mp(v[ind].ci,ind))!=cd.end())
                cd.erase(cd.find(mp(v[ind].ci,ind)));

            if(pot.find(mp(v[ind].ci,ind))!=pot.end())
                pot.erase(pot.find(mp(v[ind].ci,ind)));
            for(;ct && cd.size();) {
                ++nrob;
                int ci=cd.begin()->x,ind=cd.begin()->y;
                if(s.find(mp(v[ind].fi,ind))!=s.end())s.erase(s.find(mp(v[ind].fi,ind)));
                ct+=ci;
                cd.erase(cd.begin());
                --ct;
            }

            for(;ct && pot.size();) {
                int ci=pot.begin()->x,ind=pot.begin()->y;
                if(ci==0) break;
                ++nrob;
                ct+=ci;
                if(s.find(mp(v[ind].fi,ind))!=s.end())s.erase(s.find(mp(v[ind].fi,ind)));
                pot.erase(pot.begin());
                --ct;
            }
            break;
        }
        ++i;
    }
    for(int k=0; k<10; ++k)
    for(is i=s.begin(); i!=s.end(); ) {
        int fi=i->x,ind=i->y;
        if(fi<=S) {
            S-=fi;
            ft+=fi;
            ++nrob;
            i=s.end();
            s.erase(s.find(mp(fi,ind)));
            i=s.begin();
            continue;
        }
        ++i;
    }
    cout<<nrob+min(ct,n-nrob)<<' '<<ft;
    return 0;
}
