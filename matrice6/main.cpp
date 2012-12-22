#include <iostream>
#include <fstream>
#include <cstdlib>
#define MOD 666013
using namespace std;

int n,m,s1[6],s2[6],v1[6],v2[6],pot[1005][1005];

void l2(int p) {
  if(p==n+1) {
    int c1=0,c2=0;
    for(int i=1; i<=n; ++i) v1[i]=v1[i-1]+s1[i];
    for(int i=2; i<=n; ++i) v2[i]=v2[i-1]+s2[i];
    for(int i=1; i<=n; ++i) if(abs(v1[i]-v2[i])>1) return;
    for(int i=2; i<=n; ++i) if(abs(v2[i]-v2[i-1])>1) return;
    for(int i=1; i<=n; ++i) cout<<v1[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; ++i) cout<<v2[i]<<' ';
    cout<<"\n------------\n";
    return;
  }
  for(int i=-1; i<2; ++i) {
    s2[p]=i;
    l2(p+1);
  }
}

void l1(int p) {
  if(p==n+1) {
    l2(1);
    return;
  }
  for(int i=-1; i<2; ++i) {
    s1[p]=i;
    l1(p+1);
  }
}

int main()
{
    ifstream f("matrice6.in");
    ofstream g("matrice6.out");
    f>>n>>m;
    l1(2);
    return 0;
}
