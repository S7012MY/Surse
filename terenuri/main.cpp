#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<double,double> per;
typedef set<pair<double,int> >::iterator is;

int n,m,ind[DN],st[DN],sz;
per p[DN];
set<pair<double,int> > s;

bool cmp(const int &a,const int &b) {
    return p[a]<p[b];
}

/**
    |b.x b.y 1|
    |c.x c.y 1|
    |a.x a.y 1|
*/

bool id(per a,per b,per c) {
    double sum=b.x*c.y+c.x*a.y+a.x*b.y;
    double dif=c.x*b.y+a.x*c.y+b.x*a.y;
    return (sum-dif)<0.0;
}



void faec(per p1,per p2,int &a,int &b, int &c) {
    a=p2.y-p1.x;
    b=p1.x-p2.x;
    c=-p2.y*p1.x+p2.x*p1.y;
}

bool parte(int a,int b, int c, per p) {
    return a*p.x+b*p.y+c>0;
}

int main()
{
    ifstream f("terenuri.in");
    ofstream g("terenuri.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y;
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    st[++sz]=ind[1]; st[++sz]=ind[2];
    for(int i=3; i<=n; ++i) {
        for(;sz>1 && id(p[st[sz-1]],p[st[sz]],p[ind[i]]);--sz);
        st[++sz]=ind[i];
    }
    for(int i=n-1; i; --i) {
        for(;sz>1 && id(p[st[sz-1]],p[st[sz]],p[ind[i]]);--sz);
        st[++sz]=ind[i];
    }
    g<<--sz<<'\n';
    double sx=0,sy=0,gx,gy;
    for(int i=1; i<=sz; ++i) sx+=p[st[i]].x,sy+=p[st[i]].y;
    gx=sx/(double)sz; gy=sy/(double)sz;

    for(int i=1; i<=sz; ++i) {
        p[st[i]].x-=gx,p[st[i]].y-=gy;
        s.insert(make_pair(atan2(p[st[i]].y,p[st[i]].x),st[i]));
    }
    for(int i=0; i<m; ++i) {
        per c;
        f>>c.x>>c.y;
        c.x-=gx; c.y-=gy;
        is nxt =s.lower_bound(make_pair(atan2(c.y,c.x),0));
        if(nxt==s.end()) nxt=s.begin();
    }
    return 0;
}
