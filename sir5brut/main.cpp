#include <iostream>
#include <fstream>
#define MOD 666013
using namespace std;

int nr[555],n,l,lst=0,sir[5555];

int main()
{
  f>>n>>l;
  for(int i=1; i<l; ++i) nr[i]=1;
  for(int i=1; i<=n; ++i) {
    int a;
    f>>a;
    for(int j=1; j<=a; ++j) sir[lst+j]=(i&1);
    lst+=a-1;
  }
  for(int i=l; i<=lst; ++i) {
    sir[i]=sir[i-1];
    int ok=0;
    for(int j=i-l+1; j<=i; ++j) ok|=sir[j]
    sir[i]=(sir[i]+sir[i-l])%MOD;
  }
  g<<sir[lst]
  return 0;
}
