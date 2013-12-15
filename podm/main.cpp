#include <iostream>
#include <fstream>
#define DN 505
#define LL long long
using namespace std;

int n;
LL v[DN],b[DN][DN];

int main()
{
    ifstream f("podm.in");
    ofstream g("podm.out");
    f>>n;
    for(int i=0; i<=n; ++i) f>>v[i];
    for(int i=0; i<n-1; ++i)  b[i][i+2]=v[i]*v[i+1]*v[i+2];
    for(int lg=3; lg<=n; ++lg) for(int i=0; i+lg<=n; ++i) {
      int j=i+lg;
      LL bst=(1LL<<60);
      for(int k=i+1; k<j; ++k) bst=min(bst,b[i][k]+b[k][j]+v[i]*v[k]*v[j]);
      b[i][j]=bst;
    }
    g<<b[0][n];
    return 0;
}
