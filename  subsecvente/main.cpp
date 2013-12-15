#include <iostream>
#include <fstream>
#include <string>
#include <set>
#define LL long long
using namespace std;

int n;
string s[5];

int check(int lg) {
  if(lg>60) return 0;
  int r=0;
  LL msk=(1LL<<lg)-1;
  set<LL> nr[5];
  for(int i=1; i<n; ++i) {
    LL nc=0;
    for(int j=0; j<s[i].size(); ++j) {
      nc=((nc<<1)+s[i][j]-'a')&msk;
      if(j>=lg-1) nr[i].insert(nc);
    }
  }
  LL nc=0;
  for(int j=0; j<s[0].size(); ++j) {
      nc=((nc<<1)+s[0][j]-'a')&msk;
      if(j>=lg-1) {
        int ok=1;
        for(int i=1; i<n; ++i) if(nr[i].find(nc)==nr[i].end()) {
          ok=0;
          break;
        }
        if(ok) {
          r=1;
          break;
        }
      }
  }
  return r;
}

int main()
{
    ifstream f("subsecvente.in");
    ofstream g("subsecvente.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>s[i];
    int rez=0;
    for(int pd=64;pd; pd>>=1) if(check(rez+pd)) rez+=pd;
    g<<rez;

    return 0;
}
