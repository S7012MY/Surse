//comisia
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int t,pot[105][105];
char s[105];

int sol(int lg) {
  if(lg%3) return 0;
  memset(pot,0,sizeof(pot));
  for(int i=1; i<=lg; ++i) pot[i][i-1]=1;
  for(int lgc=3; lgc<=lg; ++lgc) {
    for(int i=1; i+lgc-1<=lg; ++i) {
      int j=i+lgc-1;
      if(lgc%3) continue;
      for(int k=i; k<j; ++k) if(pot[i][k] && pot[k+1][j]) {
        pot[i][j]=1;
        break;
      }
      if(!pot[i][j] && s[i]==s[j])
        for(int k=i+1; k<j; ++k) if(pot[i+1][k-1] && pot[k+1][j-1]) {
          //caracterul din mijloc
          pot[i][j]=1;
          break;
        }
    }
  }
  return pot[1][lg];
}

int main() {
  ifstream f("palin3.in");
  ofstream g("palin3.out");
  for(f>>t;t;--t) {
    f>>(s+1);
    int lg=strlen(s+1);
    if(sol(lg)) g<<"DA\n";
    else g<<"NU\n";
  }
}
