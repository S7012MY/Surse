#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream f("subset2.in");
  ofstream g("subset2.out");
  int n,k,rez;
  cin>>n>>k;
  rez=n-n/k-n/k;
  if(k%2==0 && n%k<k/2) ++rez;
  cout<<rez;
  g<<rez;
}