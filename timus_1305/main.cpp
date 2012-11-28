//Flux Pavilion - Bass Cannon
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <cmath>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
int n,mx=9999,Mx,my=9999,My,ind[DN];
per p[DN];
vector<per> minx,maxx,miny,maxy,sol;
set<per> s;
set<per>::iterator is;
vector<per>::iterator it;
vector<pair<double, double> > v;

bool cmp(const int &a, const int &b) {
    return atan2(v[a].x,v[a].y)<atan2(v[b].x,v[b].y);
}

int main()
{
    cin>>n;
   // assert(n>=4);
    for(int i=1; i<=n; ++i) {
        ind[i]=i;
        cin>>p[i].x>>p[i].y;
        mx=min(mx,p[i].x);
        Mx=max(Mx,p[i].x);
        my=min(my,p[i].y);
        My=max(My,p[i].y);
    }
    for(int i=1; i<=n; ++i) {
        if(p[i].x==mx) minx.push_back(p[i]);
        if(p[i].x==Mx) maxx.push_back(p[i]);
        if(p[i].y==my) miny.push_back(p[i]);
        if(p[i].y==My) maxy.push_back(p[i]);
    }

    //cout<<mx<<' '<<Mx<<' '<<my<<' '<<My<<'\n';

    sort(minx.begin(),minx.end());
    sort(maxx.begin(),maxx.end());
    sort(miny.begin(),miny.end());
    sort(maxy.begin(),maxy.end());

    s.insert(*minx.begin()); s.insert(*miny.begin());
    s.insert(*maxx.begin()); s.insert(*maxy.begin());

    it=minx.end(); --it;
    s.insert(*it);
    it=maxx.end(); --it;
    s.insert(*it);
    it=miny.end(); --it;
    s.insert(*it);
    it=maxy.end(); --it;
    s.insert(*it);

    int sx=0,sy=0;
    double cgx,cgy;

    for(is=s.begin(); is!=s.end(); ++is) sx+=is->x,sy+=is->y,sol.push_back(*is);
    cgx=(double)sx/(double)s.size();
    cgy=(double)sy/(double)s.size();
    for(is=s.begin(); is!=s.end(); ++is) v.push_back(make_pair(is->x-cgx,is->y-cgy));
    sort(ind,ind+s.size(),cmp);
    for(int i=0; i<sol.size(); ++i) cout<<sol[ind[i]].x<<' '<<sol[ind[i]].y<<'\n';
    return 0;
}
