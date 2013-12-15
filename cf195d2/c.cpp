#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n,p,v[100005];
vector<int> r;
set<int> s;

int main() {
  cin>>n;
  for(int i=1; i<=n; ++i) cin>>v[i];
  for(p=(1<<30);p;p>>=1) {
    for(int i=1; i<=n; ++i) if(v[i]&p) r.push_back(v[i]);
    if(r.size()) {
      int sand=r[0],msk=p-1;
      for(int i=1; i<r.size(); ++i) sand&=r[i];
      if(sand>=p && (sand&msk)==0) {
        for(int i=0;i<r.size(); ++i) s.insert(r[i]);
        cout<<s.size()<<'\n';
        for(set<int>::iterator it=s.begin(); it!=s.end(); ++it) cout<<(*it)<<' ';
        return 0;
      }else r.clear();
    }
  }
}
