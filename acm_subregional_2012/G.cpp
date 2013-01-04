/*#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
//freopen("inp.in","r",stdin);
  double a,b,c,d;
  for(;!feof(stdin);) {
    scanf("%lf%lf%lf%lf\n",&a,&b,&c,&d);
    int r1=0,r2=0,cc=c,cd=d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    for(;c>a+1e-8;c/=2,++r1);
    for(;d>b+1e-8;d/=2,++r1);

    cout<<min(r1,r2)<<'\n';
  }
}
*/
