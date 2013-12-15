#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#define mp make_pair
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef set<per>::iterator is;
int t,n;
per p[DN];
set<per> py;

bool check(per a, per b, per c) {
    int ptr=0;
    if(a.x==b.x) ++ptr;
    if(a.x==c.x) ++ptr;
    if(b.x==c.x) ++ptr;
    if(a.y==b.y) ++ptr;
    if(b.y==c.y) ++ptr;
    if(a.y==c.y) ++ptr;
    return ptr>1;
}

bool g3(int i, int j) {
    per a=p[i],b=p[j];
    per g1=mp(a.x,b.y),g2=mp(b.x,a.y);
    //cout<<a.x<<' '<<a.y<<" | "<<b.x<<' '<<b.y<<'\n';
    if(a.x!=b.x && a.y!=b.y) {
        if(py.find(mp(g1.y,g1.x))!=py.end() || py.find(mp(g2.y,g2.x))!=py.end()) return 1;
    }else if(a.y!=b.y) {
        //cout<<a.x<<' '<<a.y<<" | "<<b.x<<' '<<b.y<<'\n';
        if(py.lower_bound(mp(a.y,a.x+1))!=py.end() || py.lower_bound(mp(b.y,b.x+1))!=py.end()) return 1;
    }else {
        if((i!=j-1 && p[i].x==p[i+1].x) || (j<n && p[j].x==p[j+1].x)) return 1;
    }
    return 0;
}

int main()
{
    ifstream f("arbsat.in");
    ofstream g("arbsat.out");
    for(f>>t;t;--t) {
        f>>n;
        for(int i=1; i<=n; ++i) {
            f>>p[i].x>>p[i].y;
            py.insert(mp(p[i].y,p[i].x));
        }
        sort(p+1,p+n+1);
        int ok=1;
        /*for(int i=2; i<=n;++i) {
            if(!g3(i-1,i)) ok=0;
            //cout<<g3(i-1,i)<<'\n';
        }*/
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(!g3(i,j)) ok=0;
        g<<ok<<'\n';
    }
    return 0;
}
