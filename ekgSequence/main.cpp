#include <iostream>
#define DN 1000005
using namespace std;

int n,fmul[DN],minfact[DN],fol[DN];

void precalc() {
  fol[2]=2; fol[1]=1;
  for(int i=2; i<DN; ++i) fmul[i]=i;
  fmul[2]=4;
  int lst=2,cc;
  for(int i=2; i<DN; ++i) if(!minfact[i])
    for(int j=i; j<DN; j+=i) if(!minfact[j]) minfact[j]=i;
  for(int i=3; i<DN; ++i) {
    cc=lst;
    lst=DN;
    for(;cc>1;) {
      int fprim=minfact[cc];
      //cerr<<cc<<' '<<fprim<<' '<<fmul[fprim]<<'\n'; char c; cin>>c;
      for(;fol[fmul[fprim]] && fmul[fprim]+fprim<DN;fmul[fprim]+=fprim);
      lst=min(lst,fmul[fprim]);
     // cerr<<lst<<'\n';
      for(;cc%fprim==0;cc/=fprim);
    }
    fol[lst]=i;
  }
}

int main()
{
    precalc();
    for(;;) {
      cin>>n;
      if(!n) break;
      cout<<"The number "<<n<<" appears in location "<<fol[n]<<".\n";
    }
    return 0;
}
