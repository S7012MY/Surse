#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#define DN 5005
#define x first
#define y second
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,cnt,fail,col[DN];
vector<per> gr[DN];
map<int,int> nrm;

void ins(int x) {
  if(nrm.find(x)==nrm.end()) nrm[x]=cnt++;
}

void dfs(int s,int c) {
  col[s]=c+1;
  //cout<<s<<' '<<c<<":\n";
  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
    int nc=c^i->y;
   // cout<<i->x<<' '<<nc<<'\n';
    if(!col[i->x]) dfs(i->x,nc);
    else if(col[i->x]-1!=nc) fail=1;
  }
}

int main()
{
    freopen("input.txt","r",stdin);
    while(cin>>n) {
      if(n==-1) break;
      cin>>m;
      int i;
      for(i=1; i<=m; ++i) {
        int x,y; string s;
        cin>>x>>y>>s; --x;
        ins(x); ins(y);
        //cout<<x<<' '<<nrm[x]<<' '<<y<<' '<<nrm[y]<<' '<<s<<'\n';
        if(s[0]=='o') {
          gr[nrm[x]].push_back(make_pair(nrm[y],1));
          gr[nrm[y]].push_back(make_pair(nrm[x],1));
        }
        else {
          gr[nrm[y]].push_back(make_pair(nrm[x],0));
          gr[nrm[x]].push_back(make_pair(nrm[y],0));
        }
        fail=0;
        for(int i=0; i<cnt; ++i) col[i]=0;
        for(int i=0; i<cnt; ++i) if(!col[i]) dfs(i,0);
      //  cout<<'\n';
        if(fail) {
          cout<<i-1<<'\n';
          break;
        }
      }
      for(++i;i<=m; ++i) {
        int a,b; string c;
        cin>>a>>b>>c;
      }
      if(!fail)cout<<m<<'\n';
      for(int i=0; i<cnt; ++i) gr[i].clear();
      fail=0;
      cnt=0;
      nrm.clear();
    }
    return 0;
}
