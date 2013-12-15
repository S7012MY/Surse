#include <fstream>
using namespace std;

int n,nr[1005][1001];

int main()
{
    ifstream f("sir23.in");
    ofstream g("sir23.out");
    f>>n;
    for(int i=1; i<=n; ++i) nr[1][i]=i,nr[2][i]=i*i;
    for(int i=3; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        nr[i][j]=(nr[i][j-1]+nr[i-1][j-1]+nr[i-2][j-1]);
        nr[i-2][j]+=nr[i-2][j-1];
      }
    }
    g<<nr[n][n];
    return 0;
}
