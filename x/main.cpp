#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string a,b;

int n,m,q;
vector<int> z,zr;

void faZ(string s,vector<int> &z) {
  z.push_back(0);
  int n=s.size();
  int l=0,r=0,k;
  for(int i=1; i<n; ++i)
    if(i>r) {
      l=r=i;
      for(;r<n && s[r-l]==s[r];++r);
      z.push_back(r-l); --r;
    }else {
      k=i-l;
      if(z[k]<r-i+1) z.push_back(z[k]);
      else {
        l=i;
        for(;r<n && s[r-l]==s[r];++r);
        z.push_back(r-l); --r;
      }
    }
}

void pp() {
  string s,ra=a;
  reverse(ra.begin(),ra.end());
  s=b+'$'+a;
  faZ(s,z);
  s=b+'$'+ra;
  faZ(s,zr);
}

int main()
{
    ifstream f("x.in");
    ofstream g("x.out");
    f>>n>>m>>q;
    f>>a>>b;
    pp();
    for(;q;--q) {
      int l,r,mst=0,mdr=0;
      f>>l>>r;
      if(r+m+1<z.size()) mst=z[r+m+1];
      if(m+n-l+2<zr.size() && m+n-l+2>m) mdr=zr[m+n-l+2];
      g<<min(mst,mdr)<<'\n';
    }
    return 0;
}
