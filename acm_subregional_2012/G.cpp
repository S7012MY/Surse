#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
//freopen("inp.in","r",stdin);
  int a,b,c,d;
  for(;!feof(stdin);) {
    scanf("%d %d %d %d\n",&a,&b,&c,&d);
    int r1=0,r2=0;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    for(;c>a;c/=2,++r1);
    for(;d>b;d/=2,++r1);
    cout<<r1<<'\n';
  }
}
