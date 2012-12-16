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

//<parsing>
FILE* fin=fopen("kinetic.in","r");
const unsigned maxb=30000192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
    while(buf[ptr]<'0'||'9'<buf[ptr])
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    while('0'<=buf[ptr]&&buf[ptr]<='9'){
        nr=nr*10+buf[ptr]-'0';
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    }
    return nr;
}
//</parsing>

int main()
{
    ofstream g("kinetic.out");
    n=getInt(); m=getInt();
    for(int i=0; i<n; ++i) {
      int a,b;
      a=getInt(); b=getInt();
      for(int t=0; t<CNST; ++t) poz[t].push_back(make_pair(a+b*t,-1));
      poz[CNST].push_back(make_pair(b,a));
    }
    for(int t=0; t<=CNST; ++t) sort(poz[t].begin(),poz[t].end());
    //for(int i=0; i<poz[CNST].size(); ++i) cout<<getvl(poz[CNST][i],1000000)<<' ';
    //cout<<'\n';
    for(int i=0; i<m; ++i) {
      int x,y,t;
      x=getInt(); y=getInt(); t=getInt();
      if(x>y) swap(x,y);
      int st,dr;
      st=lb(t,x);
      dr=ub(t,y);
      //cout<<t<<' '<<x<<' '<<st<<' '<<y<<' '<<dr<<'\n';
      if(st==-1) {
        g<<"0\n";
        continue;
      }
      g<<dr-st<<'\n';
    }
    return 0;
}