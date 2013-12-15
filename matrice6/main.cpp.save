#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>
#define MOD 666013
#define DN 305
using namespace std;

int n,m,s1[6],s2[6],v1[6],v2[6],pot[DN][DN],nt,aux[DN][DN],rez[DN][DN],mi[DN][DN],nr[5000][5000];

void debug() {
  for(int i=1; i<=n; ++i) cout<<v1[i]<<' ';
    cout<<"- ";
    for(int i=1; i<=n; ++i) cout<<s1[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; ++i) cout<<v2[i]<<' ';
    cout<<"- ";
    for(int i=1; i<=n; ++i) cout<<s2[i]<<' ';
    cout<<"\n------------\n";
}

map<int,int> mp;

void ins(int nr) {
  if(mp.find(nr)==mp.end()) mp[nr]=++nt;
}

void l2(int p) {
  if(p==n+1) {
    int c1=0,c2=0;
    for(int i=1; i<=n; ++i) v1[i]=v1[i-1]+s1[i];
    for(int i=1; i<=n; ++i) v2[i]=v2[i-1]+s2[i];
    for(int i=1; i<=n; ++i) if(abs(v1[i]-v2[i])>1) return;
    for(int i=2; i<=n; ++i) if(abs(v2[i]-v2[i-1])>1) return;
    for(int i=2; i<=n; ++i) c1=c1*3+s1[i]+1;
    for(int i=2; i<=n; ++i) c2=c2*3+s2[i]+1;
    ins(c1); ins(c2);
    ++pot[mp[c1]][mp[c2]];
    nr[1][mp[c1]]=1;
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

void inm(int a[DN][DN],int b[DN][DN],int r[DN][DN]) {
    for(int i=1; i<=nt; ++i) for(int j=1; j<=nt; ++j) {
        int c=0;
        for(int k=1; k<=nt; ++k) c=(c+1LL*a[i][k]*b[k][j])%MOD;
        r[i][j]=c;
    }
}

void lgput(int e) {
    int c[DN][DN];
    memset(rez,0,sizeof(rez));
    memcpy(c,pot,sizeof(pot));
    for(int i=1; i<=nt; ++i) rez[i][i]=1;
    for(int i=0; (1<<i)<=e; ++i) {
        if((1<<i)&e) {
            inm(rez,c,aux);
            memcpy(rez,aux,sizeof(rez));
        }
        inm(c,c,aux);
        memcpy(c,aux,sizeof(aux));
    }
}

int main()
{
    ifstream f("matrice6.in");
    ofstream g("matrice6.out");
    f>>n>>m;
    l1(2);
    /*for(int i=2; i<=m; ++i) for(int j=0; j<=300; ++j) for(int k=0; k<=300; ++k) if(pot[j][k]){
      nr[i][k]+=(pot[j][k]*nr[i-1][j]);
      if(nr[i][k]>=MOD) nr[i][k]%=MOD;
    }
    int rez=0;
    for(int j=1; j<=nt; ++j) {
      rez+=nr[m][j];
      if(rez>=MOD) rez-=MOD;
    }*/
    //cout<<rez;
    lgput(m-1);
    int r=0;
    for(int i=1; i<=nt; ++i )for(int j=1; j<=nt; ++j) {
      r+=rez[i][j];
      //cout<<rez[i][j] <<' ';
      if(r>=MOD) r-=MOD;
    }
    g<<r;
    return 0;
}
