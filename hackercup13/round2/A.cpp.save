#include <iostream>
#include <fstream>
#include <cstring>
#include <tr1/unordered_map>
#include <bitset>
#define LL long long
#define DN 1000005
using namespace std;
using namespace tr1;
int T,n,m;
LL x1,a1,b1,c1,r1;
LL x2,a2,b2,c2,r2;
LL v1[DN],v2[DN],cnt[DN];
LL am[DN*3];

//Board1[i] = (a1 * Board1[(i-1) % N] + b1 * Board2[(i-1) % M] + c1) % r1, for 0 < i < N
//Board2[i] = (a2 * Board1[(i-1) % N] + b2 * Board2[(i-1) % M] + c2) % r2, for 0 < i < M

int main() {
  ifstream f("input.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n>>m;
    f>>v1[0]>>a1>>b1>>c1>>r1;
    f>>v2[0]>>a2>>b2>>c2>>r2;
    unordered_map<int,int> norm;
    bitset<DN> s1,s2;
    memset(am,0,sizeof(am));
    int cnt=0;
    for(int i=1; i<n; ++i) {
      if(i<n) {
        v1[i]=(a1*v1[(i-1)%n]+b1*v2[(i-1)%m]+c1)%r1;
        if(norm.find(v1[i])==norm.end()) norm[v1[i]]=++cnt;
      }
      if(i<m) {
        v2[i]=(a2*v1[(i-1)%n]+b2*v2[(i-1)%m]+c2)%r2;
        if(norm.find(v2[i])==norm.end()) norm[v2[i]]=++cnt;
      }
    }
//    for(int i=0; i<n; ++i) cout<<norm[v1[i]]<<' ';
//    cout<<'\n';
//    for(int i=0; i<m; ++i) cout<<norm[v2[i]]<<' ';
//    cout<<'\n';
    LL rez=0;
    int d=0;
    for(int i=0,j=0; i<n; ++i) {
      if(s1[norm[v1[i]]]==0) ++d;
      s1[norm[v1[i]]]=1;
//cout<<i<<' '<<j<<' '<<rez<<'\n';
      int ok=0;
      for(;s1[norm[v2[j]]]==1 && j<m;++j) {
        if(s2[norm[v2[j]]]==0) --d;
        s2[norm[v2[j]]]=1;
        if(d==0) ++rez;
        ok=1;
      }
      if(!ok && !d) ++rez;    // cout<<i<<' '<<j<<' '<<rez<<'\n';
    }
    cerr<<t<<'\n';
    g<<"Case #"<<t<<": "<<rez<<'\n';
   //while(1);
  }
}
