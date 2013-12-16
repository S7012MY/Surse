#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>
#include <bitset>
#define DN 3005
using namespace std;

int t,n,bst[3005],sz[DN];
string v,tx;

bitset<3005>ok[3005];

void preproc(string z,int p)
{
  ok[p]&=0;

  char s[DN],b[DN];
  int pi[DN],sz=0,m=0;
  for(int i=1; i<=z.size(); ++i) b[i]=z[i-1];
  for(int i=1; i<=v.size(); ++i) s[i]=v[i-1];

    sz=v.size();
    m=z.size();
    for(int i=2,q=0; i<=sz; ++i) {
        for(;q!=0 && s[i]!=s[q+1];q=pi[q]);
        if(s[i]==s[q+1]) ++q;
        pi[i]=q;
    }
    for(int i=1,q=0; i<=m; ++i) {
        for(;q!=0 && b[i]!=s[q+1];q=pi[q]);
        if(b[i]==s[q+1]) ++q;
        if(q==sz) {
            ok[p][i-sz]=1;
           // cout<<v[p]<<' '<<i-sz<<'\n';
        }
    }
}

int main() {
  ifstream f("carte.in");
  ofstream g("carte.out");
  f>>t;f.get();
  for(;t--;) {
    getline(f,tx);
    f>>n; f.get();
    for(int i=0; i<n; ++i) {
      getline(f,v);
      sz[i]=v.size();
      preproc(tx,i);
    }
    for(int i=1; i<=tx.size(); ++i) bst[i]=(1<<30);
    for(int i=0; i<=tx.size(); ++i) {
      bst[i+1]=min(bst[i+1],bst[i]+1);
      for(int j=0; j<n; ++j)
        if(ok[j][i]) bst[i+sz[j]]=min(bst[i+sz[j]],bst[i]);
     // cout<<i<<' '<<bst[i]<<'\n';
    }
    //cout<<'\n';
    g<<bst[tx.size()]<<'\n';
  }
}
