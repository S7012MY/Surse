#include <iostream>
#include <bitset>
#define DN 100005
#define DB 61
#define LL long long
using namespace std;

int n,sz;
LL v[DN],rez;
bitset<DN> ss[DB];

int gss() {
  for(int b=0,j=0,k; b<sz && j<n; ++j) {
    for(k=b;k<sz && !ss[k][j]; ++k);
    if(k==sz) continue;
    swap(ss[b],ss[k]);
    for(int k=b+1; k<sz; ++k) if(ss[k][j]) ss[k]^=ss[b];
    ++b;
  }

  for(int b=0,j; b<sz; ++b) {
    for(j=0; j<=n && !ss[b][j]; ++j);
    if(j==n) {
      ss[b][n]=0;
      return 0;
    }
  }
  return 1;
}

int main()
{
    while(cin>>n) {
       for(int i=0; i<n; ++i) cin>>v[i];
       sz=rez=0;
       for(int i=0; i<DB; ++i) ss[i]&=0;
      for(int b=DB-1; b>=0; --b) for(int i=0; i<n; ++i) if(v[i]&(1LL<<b)) ss[DB-b-1][i]=1;
      for(int b=DB-1; b>=0; --b) {
        ++sz;
        rez<<=1;
        ss[sz-1][n]=1;
        if(gss()) ++rez;
        else ss[sz-1][n]=0;
      }
      cout<<rez<<'\n';
    }
    return 0;
}
