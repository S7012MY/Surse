#include <iostream>
using namespace std;

int pd[55];

int main() {
  for(int i=0; i<=20; ++i) pd[i]=(1<<i);
  int t;
  for(cin>>t;t;--t) {
    int a;
    cin>>a;
    if((a&1) || a==0) cout<<1<<'\n';
    else {
    int lst=0,l2=0;
      for(int i=0;i<20; ++i) if(pd[i]+lst<a) lst+=pd[i],l2=pd[i];
      a-=lst;
      l2<<=1;
      l2-=a;
      ++l2;
      cout<<l2%2007<<'\n';
    }
  }
}
