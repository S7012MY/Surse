#include <fstream>
#include <algorithm>
#define DN 505
#define DT 20005
#define CNST 20002
using namespace std;

typedef pair<int,int> per;

int n,m,mt[DT][DN];
per poz[DN];

inline long long getvl(int t,int p) {
  if(t<CNST) return mt[t][p];
  return poz[p].second+poz[p].first*t;
}

inline int min(int a, int b) {
  if(a>b)return b;
  return a;
}

int lb(int u,int vl) {
  int psir=min(u,CNST);
  int ls=0,ld=n-1,m;
  for(;ls<=ld;) {
    m=(ls+ld)>>1;
    if(getvl(u,m)<vl) ls=m+1;
    else ld=m-1;
  }
  ls=min(ls,n-1);
  for(;getvl(u,ls)>=vl && ls; --ls);
  for(;getvl(u,ls)<vl && ls<n-1;++ls);
  if(getvl(u,ls)<vl) return -1;
  return ls;
}

int ub(int u,int vl) {
  int psir=min(u,CNST);
  int ls=0,ld=n-1,m;
  for(;ls<=ld;) {
    m=(ls+ld)>>1;
    if(getvl(u,m)<vl) ls=m+1;
    else ld=m-1;
  }
  ls=min(ls,n-1);
  for(;getvl(u,ls)>vl && ls>0; --ls);
  for(;getvl(u,ls)<=vl && ls<n;++ls);
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
      poz[i]=make_pair(b,a);
    }
    sort(poz,poz+n);
    for(int t=0; t<CNST; ++t) {
      for(int i=0; i<n; ++i) mt[t][i]=poz[i].second+poz[i].first*t;
      sort(mt[t],mt[t]+n);
    }

    for(int i=0; i<m; ++i) {
      int x,y,t;
      f>>x>>y>>t;
      if(x>y) swap(x,y);
      int st,dr;
      st=lb(t,x);
      if(st==-1) {
        g<<"0\n";
        continue;
      }
      dr=ub(t,y);
      g<<dr-st<<'\n';
    }
    return 0;
}
