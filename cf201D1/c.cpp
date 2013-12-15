#include <iostream>
#include <queue>
#define DN 3000005
#define LL long long
using namespace std;

int n,v[100005],dmax[DN],d[DN];
LL a,b;

int main() {
  cin>>n;
  for(int i=0; i<n; ++i) cin>>v[i];
  cin>>b>>a;
  for(int i=a; i<=b; ++i) dmax[i-a]=1;

  for(int i=0; i<n; ++i) {
    int pd;
    LL x=v[i];
    LL fct;
    for(pd=1;(1LL<<pd)*x+x-1<=a; ++pd); --pd;
    fct=(1LL<<pd);
    if(fct*x+x-1>a) fct=0;
    for(;pd;--pd) if((fct+(1LL<<pd))*x+x-1<=a) fct+=(1LL<<pd);
    for(;fct*x+x-1<a;++fct);
    //cerr<<x<<' '<<fct<<' '<<x*fct+x-1<<'\n';
    //cerr<<b+b-a-a<<'\n';while(1);
    for(LL z=fct*x+x-1-a;z<=b+b-a-a; z+=x) if(z-x+1>=0) {
     // if(z>=DN) cerr<<z<<'\n';
      dmax[z]=max(dmax[z],(int)x-1);
    }
  }
  for(int i=b+b-a-a; i>=0; --i) if(i-dmax[i+1]+1>=0)dmax[i]=max(dmax[i],dmax[i+1]-1);
 // for(int i=a; i<=b; ++i) cerr<<i<<' '<<dmax[i-a]<<'\n';
//#include <queue>
  queue<int> c;
  dmax[0]=0;
  for(c.push(b-a);!c.empty();c.pop()) {
    int fr=c.front();
    //cerr<<fr<<' ';//char q; cin>>q;
    if(d[0]) break;
    if(!d[fr-dmax[fr]]) {
      d[fr-dmax[fr]]=d[fr]+1;
      c.push(fr-dmax[fr]);
    }
    if(fr && !d[fr-1]) {
      d[fr-1]=d[fr]+1;
      c.push(fr-1);
    }
  }
  cout<<d[0];
}
