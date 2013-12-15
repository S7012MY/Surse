#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#define MOD 666013
using namespace std;

int nr[2][1005][1005];//numarul de secvente care incep cu i au lungimea j si frumusetea k;
char s[1005];

int main() {
  freopen("frumusete.in","r",stdin);
  freopen("frumusete.out","w",stdout);
  nr[0][0][0]=1;
  for(int i=1; i<=1000; ++i) {
    for(int j=0; j<=1000; ++j) {
      nr[0][i][j]=nr[0][i-1][j];
      nr[0][i][j]+=nr[1][i-1][j];
      nr[1][i][j]=nr[0][i-1][j];
      if(j) nr[1][i][j]+=nr[1][i-1][j-1];
      if(nr[1][i][j]>=MOD) nr[1][i][j]-=MOD;
      if(nr[0][i][j]>=MOD) nr[0][i][j]-=MOD;
    }
  }
 // cout<<nr[0][5][4]<<'\n';
  int t,k;
  for(scanf("%d",&t);t--;) {
    char c;
    scanf("%d",&k);
    gets(s);
    int lg=strlen(s);
    int r=0,gp=0;
    for(int i=0; i<lg; ++i) if(s[i]=='1'){
      if(k-gp>=0) r+=nr[0][lg-i][k-gp];
      if(r>=MOD) r-=MOD;
      if(i && s[i-1]=='1') ++gp;
      //cout<<s<<' '<<gp<<' '<<s.size()-i<<' '<<k-gp<<' '<<nr[0][s.size()-i][k-gp]<<'\n';
    }
    if(gp==k) ++r;
    printf("%d\n",r);
  }
  return 0;
}
