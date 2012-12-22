#include <iostream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

bitset<DN> viz;
int n,m,fs[DN*2],lst[DN*2],rez[DN],ai[4*DN],nr[4*DN],sz,gls,gld,vl,nrmar[4*DN];
vector<int> gr[DN],leg[DN];

void update(int vn, int ls, int ld) {
  if(ld<ls || gls>ld || gld<ls) return;
  //cout<<vn<<' '<<ls<<' '<<ld<<' '<<gls<<' '<<gld<<'\n';
  if(gls<=ls && ld<=gld) {
    ai[vn]+=vl;
    if(vl==1) {
      nr[vn]=1;
      nrmar[vn]=(ld-ls+1);
    }
    if(ai[vn]==0) {
      nr[vn]=0;
      nrmar[vn]=nrmar[2*vn]+nrmar[2*vn+1];
    }
    return;
  }
  int fs=(vn<<1),m=(ls+ld)>>1;
  if(gls<=m) update(fs,ls,m);
  if(m<gld) update(fs+1,m+1,ld);
  nrmar[vn]=nrmar[2*vn]+nrmar[2*vn+1];
}

void count(int s) {
  viz[s]=1;
  if(leg[s].size()) {
    gls=fs[s]; gld=lst[s]; vl=1;
    update(1,1,sz);
  }
  for(it i=leg[s].begin(); i!=leg[s].end(); ++i) {
    gls=fs[*i]; gld=lst[*i]; vl=1;
    update(1,1,sz);
  }
  rez[s]=nrmar[1];
  if(rez[s]) --rez[s];
  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) count(*i);

  if(leg[s].size()) {
    gls=fs[s]; gld=lst[s]; vl=-1;
    update(1,1,sz);
  }
  for(it i=leg[s].begin(); i!=leg[s].end(); ++i) {
    gls=fs[*i]; gld=lst[*i]; vl=-1;
    update(1,1,sz);
  }
}

void dfs(int s) {
    viz[s]=1;
    fs[s]=++sz;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
    lst[s]=sz;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<n; ++i) {
      int a,b;
      cin>>a>>b;
      gr[a].push_back(b);
      gr[b].push_back(a);
    }
    dfs(1);
    for(int i=1; i<=m; ++i) {
      int a,b;
      cin>>a>>b;
      leg[a].push_back(b);
      leg[b].push_back(a);
    }
    viz&=0;
    count(1);
    for(int i=1; i<=n; ++i)
      cout<<rez[i]<<' ';
    return 0;
}
