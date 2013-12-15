#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define DN 1000005
using namespace std;

int n,v[DN],cv[DN],md[DN];

int bulan() {
  int rmin=(1<<30);
  md[n-1]=1; v[n-1]=(1<<30);
  for(int i=n-2; i>=0; --i) {
    md[i]=md[i+1];
    if(!(v[i]<v[i+1])) {
      v[i]=v[i+1]-1;
      ++md[i];
    }
  }
  v[0]=cv[0];
  int r=0;
  for(int i=1; i<n-1; ++i) {
    v[i]=cv[i];
    if(!(v[i-1]<v[i])) {
      ++r;
      v[i]=v[i-1]+1;
      if(!(v[i]<v[i+1])) rmin=min(rmin,r+n-1-i);
      else rmin=min(rmin,r+md[i+1]);
    }
    else rmin=min(rmin,r+md[i+1]);
  }
  return rmin;
}

int main() {
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>v[i];
        cv[i]=v[i];
    }
    int r=0;
    for(int i=1; i<n; ++i) if(!(v[i-1]<v[i])) {
        v[i]=v[i-1]+1;
        ++r;
    }
    for(int i=0; i<n; ++i) v[i]=cv[i];
    int r2=0,ok=1;
    for(int i=n-1; i>=0;--i) if(!(v[i]<v[i+1])) {
        v[i]=v[i+1]-1;
        ++r2;
        if(v[i]<1) ok=0;
    }
    if(ok) r=min(r,r2);
    for(int i=0; i<n; ++i) v[i]=cv[i];
    r2=0;
    int imin=n;
    for(int i=n-2; i>=0;--i) if(!(v[i]<v[i+1])) imin=i;
    for(int i=n-1; i>=0; --i) if(i>=imin) ++r2;
    r=min(r,r2);
    r=min(r,bulan());
    cout<<r;
    return 0;
}
