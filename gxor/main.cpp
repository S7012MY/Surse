#include <iostream>
#include <fstream>
#include <map>
#include <bitset>
#define DG 400
#define MOD 34949
#define mp make_pair
using namespace std;

map<pair<int,int>,int> nrm;
int n,g,nrv,fixe;
bitset<DG*10> ss[DG];

void ins(int a,int b) {
  if(nrm.find(mp(a,b))==nrm.end()) nrm[mp(a,b)]=nrv++;
}

void cnt() {
  for(int i=0,j=0,k; i<g && j<nrv;) {
    for(k=i;k<g && !ss[k][j];++k);
    if(k==g) {
      ++j; continue;
    }
    swap(ss[i],ss[k]);
    for(int k=i+1; k<g; ++k) if(ss[k][j]) ss[k]^=ss[i];
    ++i; ++j; ++fixe;
  }
}

#define LL long long
LL put(int b, int e) {
    LL r=1,x=b;
    for(;e;e>>=1) {
      if(e&1) r=(r*x)%MOD;
      x=(x*x)%MOD;
    }
    return r;
}

int main()
{
    ifstream f("gxor.in");
    ofstream go("gxor.out");
    f>>n>>g;
    for(int i=0; i<g; ++i) {
      int x1,y1,x2,y2,r;
      f>>x1>>y1>>x2>>y2>>r;
      ins(x1-1,y1-1); ins(x1-1,y2); ins(x2,y1-1); ins(x2,y2);
      ss[i][nrm[mp(x1-1,y1-1)]]=ss[i][nrm[mp(x1-1,y2)]]=ss[i][nrm[mp(x2,y1-1)]]=ss[i][nrm[mp(x2,y2)]]=1;
      ss[i][4*g]=r;
    }
    cnt();
    for(int i=0,j; i<g; ++i) {
      for(j=0; j<=4*g && !ss[i][j]; ++j);
      if(j==4*g) {
        go<<"0";
        return 0;
      }
    }
    go<<put(2,n*n-fixe);
    return 0;
}
