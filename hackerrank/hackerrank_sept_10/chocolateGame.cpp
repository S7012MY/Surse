#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n,x,r=0,v[100005],d[100005];
map<int,int> sp[2];

int main() {
    cin>>n;
    int sp=0,si=0;
    for(int i=1; i<=n; ++i) {
      cin>>v[i];
      d[i]=v[i]-v[i-1];
    }
    for(int i=1; i<=n; ++i) {
      int sp=0,si=0;
      if(i&1) si^=v[i];
      else sp^=v[i];
      for(int j=i+1; j<=n; ++j) {
        if(j&1) si^=d[j];
        else sp^=d[j];
        int sx=0;
        if((j-i+1)&1) {
          if(i&1) sx=si;
          else sx=sp;
        }else {
          if(i&1) sx=sp;
          else sx=si;
        }
        if(sx) {
          ++r;
          //cout<<i<<' '<<j<<' '<<sp<<' '<<si<<' '<<'\n';
          //for(int i=0; i<a.size(); ++i) cout<<a[i]<<' ';
          //cout<<'\n';
         // for(int k=i-1; k>=j; k-=2) cout<<d
        }
      }
    }
    cout<<r;
    return 0;
}
