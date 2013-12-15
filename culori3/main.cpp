#include <iostream>
#include <fstream>
#define DN 5005
#define DIM 10001
using namespace std;
ifstream f("culori3.in");
ofstream g("culori3.out");
typedef short Huge[DIM];

int n;
Huge dp[2][5],rez;

//alb = 0
//albastru=1
//rosu=2
//verde=3
//galben=4;

void Add(Huge A, Huge B)
/* A <- A+B */
{ int i,T=0;

  if (B[0]>A[0])
    { for (i=A[0]+1;i<=B[0];) A[i++]=0;
      A[0]=B[0];
    }
    else for (i=B[0]+1;i<=A[0];) B[i++]=0;
  for (i=1;i<=A[0];i++)
    { A[i]+=B[i]+T;
      T=A[i]/10;
      A[i]%=10;
    }
  if (T) A[++A[0]]=T;
}

void AtribHuge(Huge H, Huge X)
{
  int i;
  for (i=0; i<=X[0]; i++) H[i]=X[i];
}

void WriteHuge(Huge X)
{
  int i;
  for (i=X[0]; i; i--)
     g<<X[i];
}

int main()
{
    f>>n;
    for(int i=0; i<5; ++i) dp[1][i][0]=dp[1][i][1]=1;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<5; ++j) dp[i&1][j][0]=0;
        AtribHuge(dp[i&1][0],dp[(i-1)&1][1]);
        AtribHuge(dp[i&1][1],dp[(i-1)&1][0]); Add(dp[i&1][1],dp[(i-1)&1][2]);
        AtribHuge(dp[i&1][2],dp[(i-1)&1][1]); Add(dp[i&1][2],dp[(i-1)&1][3]);
        AtribHuge(dp[i&1][3],dp[(i-1)&1][2]); Add(dp[i&1][3],dp[(i-1)&1][4]);
        AtribHuge(dp[i&1][4],dp[(i-1)&1][3]);;
    }
    for(int i=0; i<5; ++i) Add(rez,dp[n&1][i]);
    WriteHuge(rez);
    return 0;
}
