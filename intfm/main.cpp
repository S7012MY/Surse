#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#define DN 2005
#define x first
#define y second
using namespace std;

map<int,int> mp;
set<int> s;
typedef pair<int,int> per;
pair<per,per> v[DN];
int n,bst[8005][8005];

int main() {
    ifstream f("intfm.in");
    ofstream g("intfm.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        int a,b,lg;
        f>>a>>b;
        lg=(b-a)/5;
        v[i].x.x=a; s.insert(a);
        v[i].x.y=a+2*lg; s.insert(a+2*lg);
        v[i].y.x=a+3*lg; s.insert(a+3*lg);
        v[i].y.y=b; s.insert(b);
    }
    int cnt=0;
    for(set<int>::iterator is=s.begin(); is!=s.end(); ++is) mp[*is]=++cnt;
    for(int i=1; i<=n; ++i) {
        v[i].x.x=mp[v[i].x.x];
        v[i].x.y=mp[v[i].x.y];
        v[i].y.x=mp[v[i].y.x];
        v[i].y.y=mp[v[i].y.y];
        cout<<v[i].x.x<<' '<<v[i].x.y<<'|'<<v[i].y.x<<' '<<v[i].y.y<<'\n';
    }
    sort(v+1,v+n+1);
    //g<<memo(mp[*s.begin(),*s.end()])
    return 0;
}
