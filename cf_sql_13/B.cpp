#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
#define LL long long
using namespace std;

LL n;
vector<LL> v;

long double lgput(long double b,int exp) {
  long double rez=1;
  for(int i=1; i<=exp; ++i) rez*=b;
  return rez;
}

int main() {
  cin>>n;
  for(int x=1; (1LL<<x)<=n; ++x) {
    //t^2+t(2^(x+1)-3)-2*n=0
    long double b=lgput(2,x+1)-3;
    long double delta=b*b+(long double)8*n;
    long double drad=sqrt(delta);
    if(drad-(long long)drad) continue;
    long double x1=(-b+drad)/2.0;
    long double x2=(-b-drad)/2.0;

    long double sum=0;
    for(int i=0; i<x; ++i) sum+=x1*lgput(2,i);
    if(x1-(long long)x1==0 && x1>0) v.push_back(x1+sum);
    sum=0;
    for(int i=0; i<x; ++i) sum+=x2*lgput(2,i);

    if(x2-(long long)x2==0 && x2>0) v.push_back(x2+sum);
  }
  //x==0
  long long ls=1,ld=20000000000LL,m;
  for(;ls<=ld;) {
    m=(ls+ld)/2;
    if((m*(m-1))/2<n) ls=m+1;
    else {
      if((m*(m-1))/2==n) {
        if(m%2) v.push_back(m);
        break;
      }else ld=m-1;
    }
  }
  if(v.size()==0) {
    cout<<-1;
    return 0;
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size(); ++i) cout<<v[i]<<'\n';
}
