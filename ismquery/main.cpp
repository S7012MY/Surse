#include <iostream>
#include <fstream>
#include <cstring>
#define DN 400005
#define x first
#define y second
using namespace std;

int n,m,v[DN],rez[6][DN],st[6][DN],psir[6][DN],sz[6],unde[6],G,h;

int get(int nr) {
  //cout<<nr<<' ';
  int pmin=(1<<30),u=-1;
  for(int j=1; j<=5; ++j) if(unde[j]>0 && st[j][unde[j]]>nr && pmin>psir[j][unde[j]]) {
    pmin=psir[j][unde[j]];
    u=j;
  }
  //cout<<u<<' '<<pmin<<'\n';
  --unde[u];
  return pmin;
}

void push(int u,int nr,int poz) {
  if(u>5) return;
  for(;nr<st[u][sz[u]] && sz[u]>0;) {
    push(u+1,st[u][sz[u]],psir[u][sz[u]]);
    --sz[u];
  }
  st[u][++sz[u]]=nr;
  psir[u][sz[u]]=poz;
}

void dst() {
  for(int i=1; i<=5; ++i) {
    for(int j=1; j<=sz[i]; ++j) cout<<st[i][j]<<' ';
    cout<<'\n';
    for(int j=1; j<=sz[i]; ++j) cout<<psir[i][j]<<' ';
    cout<<"\n\n";
  }
  cout<<"\n--------\n";
}

int main()
{
    ifstream f("ismquery.in");
    ofstream g("ismquery.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) f>>v[i];

    for(int i=n; i; --i) {
      for(int j=1; j<=5; ++j) unde[j]=sz[j];
      for(int j=1; j<=5; ++j) {
        rez[j][i]=get(v[i]);
        //cout<<i<<' '<<j<<' '<<rez[j][i]<<'\n';
        //dst();
        if(rez[j][i]>n) {
          rez[j][i]=0;
          break;
        }
      }
      push(1,v[i],i);
      //dst();
    }
    f>>G>>h;
    //pi = 1 + (i + pi-1*G)%N
    //ki = 1 + (i + ki-1*H)%5
    int pp=1,kp=1,pc,kc;
    for(int i=1; i<=m; ++i) {
      pc=1+(i+pp*G)%n;
      kc=1+(i+kp*h)%5;
      cout<<pc<<' '<<kc<<'\n';
      g<<rez[kc][pc]<<'\n';
      pp=pc; kp=kc;
    }
    return 0;
}
