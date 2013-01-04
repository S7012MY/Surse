#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

per p;
int t,n,m;
vector<per> v;
multiset<int> miy;
multiset<int,greater<int> > may;

int faar(int minx,int maxx, int miny, int maxy) {
  --minx; --miny; ++maxx; ++maxy;
  return (maxx-minx)*(maxy-miny);
}

int solve(int a,int b) {
  int r=(1<<30);
  for(int i=a; i+m-1<=b && i-a+1<=m; ++i) {
    miy.insert(v[i].y);
    may.insert(v[i].y);
  }
  for(int i=a+m-1;i+m-1<=b;++i) {
    r=min(r,faar(v[a].x,v[a].y,*miy.begin(),*may.begin()));
    miy.erase(miy.find(v[i-m+1].y));
    may.erase(may.find(v[i-m+1].y));
    miy.insert(v[i].y);
    may.insert(v[i].y);
  }
  return r;
}

int main() {
  for(cin>>t;t;--t) {
  int r=(1<<30);
    v.clear();

    cin>>n>>m;
    for(int i=1; i<=n; ++i) {
      cin>>p.x>>p.y;
      v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); ++i) for(int j=i+1; j<v.size(); ++j) r=min(r,solve(i,j));

    cout<<r<<'\n';
  }
}
