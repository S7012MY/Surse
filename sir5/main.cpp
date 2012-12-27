#include <iostream>
#include <fstream>
#include <cstring>
#define DN 105
#define MOD 666013
using namespace std;

int n,l,a,mt[55][55],rez[DN][DN],aux[DN][DN],pot[DN][DN],v[DN],lst=1,vr[DN],anxt;

void inm(int a[DN][DN],int b[DN][DN],int r[DN][DN]) {
    for(int i=1; i<=l; ++i) for(int j=1; j<=l; ++j) {
        int c=0;
        for(int k=1; k<=l; ++k) c=(c+1LL*a[i][k]*b[k][j])%MOD;
        r[i][j]=c;
    }
}

void lgput(int e) {
    int c[DN][DN];
    e=max(0,e);
    memset(rez,0,sizeof(rez));
    memcpy(c,pot,sizeof(pot));
    for(int i=1; i<=l; ++i) rez[i][i]=1;
    for(int i=0; (1<<i)<=e; ++i) {
        if((1<<i)&e) {
            inm(rez,c,aux);
            memcpy(rez,aux,sizeof(rez));
        }
        inm(c,c,aux);
        memcpy(c,aux,sizeof(aux));
    }
}

void inmv(){
  memset(vr,0,sizeof(vr));
  for(int i=1; i<=l; ++i) for(int j=1; j<=l; ++j) vr[i]=(vr[i]+v[j]*rez[i][j])%MOD;
}

int main()
{
    ifstream f("sir5.in");
    ofstream g("sir5.out");
    f>>n>>l;
    for(int i=1; i<l; ++i) pot[i][i+1]=1;
    pot[l][1]=pot[l][l-1]=1;
    for(int i=1; i<=n; ++i) if(i&1){
      f>>a;
      lgput(a-l);
      if(i==1){
        for(int j=1; j<=l; ++j) v[j]=lst;
        v[l]=2;
      }
      inmv();
      if(i<n) f>>anxt;
      else anxt=0;
      lst=vr[l];
      for(int j=l+1; j<=min(2*l,l+anxt); ++j) {
        vr[j]=(vr[j-1]+vr[j-l])%MOD;
        v[i-l]=vr[j];
        lst=vr[j];
      }
      cout<<i<<":\n";
      for(int j=1; j<=min(2*l,l+anxt); ++j) cout<<vr[j]<<' ';
      cout<<'\n';
    }
    g<<lst;
    return 0;
}
