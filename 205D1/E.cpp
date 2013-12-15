#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int n,v[3005],inv,rez,ti;

int main() {
  srand(time(NULL));
  cin>>n; for(int i=0; i<n; ++i) cin>>v[i];
  for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) if(v[i]>v[j]) ++inv;
  rez=inv;
  ti=inv;
  for(int r=0; r<=3000000; ++r) {
    int i=rand()%n;
    if(v[i]==0) continue;
    for(int j=i+1; j<n; ++j) if(v[i]>v[j]) --inv;
    for(int j=i-1; j>=0; --j) if(v[j]>v[i]) --inv;
    v[i]=-v[i];
    for(int j=i+1; j<n; ++j) if(v[i]>v[j]) ++inv;
    for(int j=i-1; j>=0; --j) if(v[j]>v[i]) ++inv;
    rez=min(rez,inv);
    if(rez==0) break;
  }
  cout<<rez;
}

