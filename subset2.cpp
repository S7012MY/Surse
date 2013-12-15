#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream f("subset2.in");
  ofstream g("subset2.out");
  int n,k,rez;
  f>>n>>k;
  rez=n/k*((k-1)/2)+min(n%k,(k-1)/2)+1;
  if(k%2==0) ++rez;
  g<<rez;
}