#include <iostream>
using namespace std;

int t,n,m;
long long dmin[55][55],bst[(1<<17)][20];

int main() {
  for(cin>>t;t;--t) {
    cin>>n>>m;
    ++n;
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dmin[i][j]=(1<<30);
    for(int i=0; i<(1<<n); ++i) for(int j=0; j<=n; ++j) bst[i][j]=(1<<30);
    for(int i=0; i<m; ++i) {
      int a,b,c;
      cin>>a>>b>>c;
      dmin[a][b]=dmin[b][a]=c;
    }
    for(int k=0; k<n; ++k) for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
      dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[k][j]);
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) cout<<dmin[i][j]<<' ';
      cout<<'\n';
    }
  }
}
