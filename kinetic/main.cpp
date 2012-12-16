#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define DN 505
#define DT 10005
using namespace std;

int n,m;
vector<int> poz[DN*DT];

int lb(int u,int vl) {
  int ls=0,ld=poz[u].size()-1,m;
  for(;ls<=ld;) {
    m=(ls+ld)>>1;
    if(poz[u][m]<vl) ls=m+1;
    else ld=m-1;
  }
  for(;poz[u][ls]>=vl && ls; --ls);
  for(;poz[u][ls]<vl && ls<poz[u].size()-1;++ls);
  //cout<<u<<' '<<vl<<' '<<ls<<'\n';
  return ls;
}

int main()
{
    ifstream f("kinetic.in");
    ofstream g("kinetic.out");
    f>>n>>m;
    for(int i=0; i<n; ++i) {
      int a,b;
      f>>a>>b;
      for(int t=0; t<10001; ++t) poz[t].push_back(a+b*t);
    }
    for(int t=0; t<10001; ++t) sort(poz[t].begin(),poz[t].end());
    for(int i=0; i<m; ++i) {
      int x,y,t;
      f>>x>>y>>t;
      if(x>y) swap(x,y);
      g<<lb(t,y)-lb(t,x)<<'\n';
    }
    return 0;
}
