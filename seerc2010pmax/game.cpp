#include <iostream>
using namespace std;

int n,pot[1005][1005],mt[1005][1005],sl[1005][1005],sc[1005][1005];

int main() {
  for(;cin>>n;) {
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
      cin>>mt[i][j];
      sl[i][j]=sl[i-1][j]+mt[i][j];
      sc[i][j]=sc[i][j-1]+mt[i][j];
      pot[i][j]=(sl[i][j]%2==0 && !pot[i][j-1]) || (sc[i][j]%2==0 && !pot[i-1][j]);
      //cout<<i<<' '<<j<<' '<<pot[i][j]<<'\n';
    }
    if(pot[n][n]) cout<<"W\n";
    else cout<<"L\n";
  }
}