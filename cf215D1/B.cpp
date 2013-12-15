#include <iostream>
#include <map>
#include <set>
#define DN 500005
using namespace std;

int n,m,p,a[DN],b[DN];
map<int,int> fr,frb;
set<int> pp;

int main() {
  cin>>n>>m>>p;
  for(int i=1; i<=n; ++i) cin>>a[i];
  for(int i=1; i<=m; ++i) cin>>b[i];
  for(int i=1; i<=p; ++i) {
    int lg=0;
    for(int j=1; j<=m; ++j) fr[b[j]]=frb[b[j]]=0;
    for(int j=1; j<=m; ++j) ++frb[b[j]];

    for(int j=i; j<=n; j+=p) {
      int scos=j-p*m;
      if(scos>0) {
        if(fr.find(a[scos])!=fr.end()) {
          --fr[a[scos]];
          if(fr[a[scos]]==frb[a[scos]]-1) --lg;
          if(fr[a[scos]]==frb[a[scos]]) ++lg;
        }
      }
      if(fr.find(a[j])!=fr.end()) {
        ++fr[a[j]];
        if(fr[a[j]]==frb[a[j]]) ++lg;
        if(fr[a[j]]==frb[a[j]]+1) --lg;
      }
      if(lg==fr.size()) pp.insert(j-p*(m-1));
      //cout<<lg<<' ';
    }
  }
  cout<<pp.size()<<'\n';
  for(set<int>::iterator it=pp.begin(); it!=pp.end(); ++it) cout<<*it<<' ';
}
