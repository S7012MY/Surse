#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

per p;
int t,n,m;
vector<per> v,vy;
multiset<int> miy;
multiset<int,greater<int> > may;

int faar(int minx,int maxx, int miny, int maxy) {
  --minx; --miny; ++maxx; ++maxy;
  cout<<minx<<' '<<miny<<' '<<maxx<<' '<<maxy<<' '<<(maxx-minx)*(maxy-miny)<<'\n';
  return (maxx-minx)*(maxy-miny);
}

int solve(int a,int b) {
  int r=(1<<30);
  cout<<a<<' '<<b<<":\n";
  for(int i=a; i<=b; ++i) vy.push_back(make_pair(v[i].y,v[i].x));
  sort(vy.begin(),vy.end());
  for(int i=a; i+m-1<=b; ++i) r=min(r,faar(v[a].x,v[b].x,vy[i].x,vy[i+m-1].x));
  vy.clear();
  return r;
}

int main() {
freopen("inp.in","r",stdin);
  for(cin>>t;t;--t) {
  int r=(1<<30);
    v.clear();

    cin>>n>>m;
    for(int i=1; i<=n; ++i) {
      cin>>p.x>>p.y;
      v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); ++i) for(int j=i+m-1; j<v.size(); ++j) r=min(r,solve(i,j));
    cout<<r<<'\n';
    cerr<<"---------\n";
  }
}
