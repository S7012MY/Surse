#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int,int> mp;

int main() {
  ifstream f("pariuri.in");
  ofstream g("pariuri.out");
  f>>n;
  for(int i=0; i<n; ++i) {
    f>>m;
    for(int j=0; j<m; ++j) {
      int timp,bani;
      f>>timp>>bani;
      //cout<<timp<<' '<<bani<<'\n';
      if(mp.find(timp)==mp.end()) mp[timp]=bani;
      else mp[timp]+=bani;
    }
  }
  g<<mp.size()<<'\n';
  for(unordered_map<int,int>::iterator im=mp.begin(); im!=mp.end(); ++im) g<<im->first<<' '<<im->second<<'\n';
}
