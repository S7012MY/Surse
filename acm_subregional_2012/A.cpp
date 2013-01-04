/*#include <iostream>
using namespace std;

int n,q,mt[1005][1005];

int main() {
  cin>>n>>q;
  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
    cin>>mt[i][j];
    mt[i][j]+=mt[i-1][j]+mt[i][j-1];
    mt[i][j]-=mt[i-1][j-1];
  }
  for(;q;--q) {
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    cout<<mt[r2][c2]-mt[r1-1][c2]-mt[r2][c1-1]+mt[r1-1][c1-1]<<'\n';
  }
}
*/
