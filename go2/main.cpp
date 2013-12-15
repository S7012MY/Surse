#include <fstream>
#include <bitset>
#define DN 105
#define MOD 1000000007
#define LL long long
using namespace std;

int n,m,nvl,rf=1,sz;
char b[DN][DN];
bitset<DN> infl[DN][DN],ss[DN*DN];

void cnt() {
  int i=1,j=1,k;
  for(;i<=sz && j<=m;) {
    for(k=i;k<=sz && !ss[k][j]; ++k);
    if(k==sz+1) {
      rf=(rf+rf)%MOD;
      ++j;
      continue;
    }
    swap(ss[i],ss[k]);
    for(k=i+1; k<=sz; ++k) if(ss[k][j]) ss[k]^=ss[i];
    ++i; ++j;
  }
  for(;j<=m; ++j,rf=(rf+rf)%MOD);
}

int main()
{
    ifstream f("go2.in");
    ofstream g("go2.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>b[i][j];
    for(int j=1; j<=m; ++j) {
      infl[1][j][j]=1;
      if(b[1][j]!='?') {
        ss[++sz]=infl[1][j];
        ss[sz][m+1]=b[1][j]-'0';
      }
    }
    for(int i=2; i<=n; ++i) for(int j=1; j<=m; ++j) {
       infl[i][j]=infl[i-1][j-1]^infl[i-2][j]^infl[i-1][j+1];
       if(b[i][j]!='?') {
         ss[++sz]=infl[i][j];
         ss[sz][m+1]=b[i][j]-'0';
       }
    }
    for(int j=1; j<=m; ++j)
      ss[++sz]=infl[n][j-1]^infl[n-1][j]^infl[n][j+1];
    cnt();
    for(int i=1,j=1; i<=sz; ++i) {
      for(;j<=m+1 && !ss[i][j]; ++j);
      if(j==m+1) {
        g<<0;return 0;
      }
    }
    g<<rf;
    return 0;
}
