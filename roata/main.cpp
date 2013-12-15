#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#define x first
#define y second
#define DN 200005
using namespace std;

typedef pair<long long,pair<int,int> >per;

int n,p,c[DN],lst;
long long r1;
set<per> s;
vector<int> sol;

int main()
{
    ifstream f("roata.in");
    ofstream g("roata.out");
    f>>n>>p;
    for(int i=1; i<=n; ++i) s.insert(make_pair(0,make_pair(0,i)));
    for(int i=1; i<=p; ++i) {
        f>>c[i];
        r1+=c[i];
        per beg=*s.begin();
        s.erase(s.begin());
        s.insert(make_pair(beg.x+c[i],make_pair(i,beg.y.y)));
        sol.push_back(beg.y.x);
        if(beg.y.x) lst=beg.y.y;
    }
    for(;s.size();) {
        sol.push_back(s.begin()->y.x);
        if(sol[sol.size()-1]) lst=s.begin()->y.y;
        s.erase(s.begin());
    }
    g<<r1<<'\n';
    for(int i=0; i<sol.size(); ++i) if(sol[i]) g<<sol[i]<<' ';
    g<<'\n'<<lst;
    return 0;
}
