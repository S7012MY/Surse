#include <fstream>
#include <algorithm>
#include <vector>
#define DN 505
#define DT 20005
#define CNST 20002
using namespace std;

int n,m;
vector<pair<int,int> > poz[DT];

long long getvl(pair<int,int> vl, int t) {
  if(vl.second==-1) return vl.first;
  return vl.second+vl.first*t;
}

inline int min(int a, int b) {
  if(a>b)return b;
  return a;
}

int lb(int u,int vl) {
  int psir=min(u,CNST);
  int ls=0,ld=poz[psir].size()-1,m;
  for(;ls<=ld;) {
    m=(ls+ld)>>1;
    if(getvl(poz[psir][m],u)<vl) ls=m+1;
    else ld=m-1;
  }
  ls=min(ls,(int)poz[psir].size()-1);
  for(;getvl(poz[psir][ls],u)>=vl && ls; --ls);
  for(;getvl(poz[psir][ls],u)<vl && ls<poz[psir].size()-1;++ls);
  if(getvl(poz[psir][ls],u)<vl) return -1;
  return ls;
}

int ub(int u,int vl) {
  int psir=min(u,CNST);
  int ls=0,ld=poz[psir].size()-1,m;
  for(;ls<=ld;) {
    m=(ls+ld)>>1;
    if(getvl(poz[psir][m],u)<vl) ls=m+1;
    else ld=m-1;
  }
  ls=min(ls,(int)poz[psir].size()-1);
  for(;getvl(poz[psir][ls],u)>vl && ls>0; --ls);
  for(;getvl(poz[psir][ls],u)<=vl && ls<poz[psir].size();++ls);
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
      for(int t=0; t<CNST; ++t) poz[t].push_back(make_pair(a+b*t,-1));
      poz[CNST].push_back(make_pair(b,a));
    }
    for(int t=0; t<=CNST; ++t) sort(poz[t].begin(),poz[t].end());
    for(int i=0; i<m; ++i) {
      int x,y,t;
      f>>x>>y>>t;
      if(x>y) swap(x,y);
      int st,dr;
      st=lb(t,x);
      dr=ub(t,y);
      if(st==-1) {
        g<<"0\n";
        continue;
      }
      g<<dr-st<<'\n';
    }
    return 0;
}
