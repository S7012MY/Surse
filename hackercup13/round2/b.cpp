#include <iostream>
#include <fstream>
using namespace std;

int T,n,h;

int main() {
  ifstream f("input.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n>>h;
    g<<"Case #"<<t<<": ";
    for(;h--;) {
      int a,b; f>>a>>b;
      int bune=0,proaste=0;
      for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=a && j!=b) {
        if(a+b>i+j)++bune;
        else ++proaste;
      }
      if(bune>proaste) g<<"B";
      else g<<"F";
    }
    g<<'\n';
  }
}
