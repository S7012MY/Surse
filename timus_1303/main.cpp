#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define DN 100005
using namespace std;

typedef pair<int, int> per;

int m,a,b;
vector<per> p,sl,sol;

bool cmp(const per &a, const per &b) {
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}

int main()
{
    cin>>m;
    for(;;) {
        cin>>a>>b;
        if(0==a && 0==b) break;
        p.push_back(make_pair(a,b));
    }
    sort(p.begin(),p.end(),cmp);
    per lst(0,0),nxt;
    int zz=0;
    for(int i=0; i<p.size(); ++i) {
        if(lst.x>=p[i].x && p[i].y>lst.y) lst=p[i];
        else if(lst.x<=p[i].x && p[i].x<=lst.y && p[i].y>lst.y) {
            sl.push_back(lst);
            lst=p[i];
        }
    }
    if(lst!=make_pair(0,0)) sl.push_back(lst);
    sort(sl.begin(),sl.end());
    for(int i=0; i<sl.size(); ++i) {
        if(i<sl.size()-1&& sl[i+1].x<=0) continue;
        sol.push_back(sl[i]);
        if(sl[i].x>m) break;
    }
    for(int i=1; i<sol.size(); ++i) if(sol[i].x>sol[i-1].y) {
        cout<<"No solution";
        return 0;
    }
    if(0==sol.size()) {
        cout<<"No solution";
        return 0;
    }
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) cout<<sol[i].x<<' '<<sol[i].y<<'\n';
    return 0;
}
