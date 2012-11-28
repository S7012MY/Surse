#include <iostream>
using namespace std;

typedef int Huge[1005];
int k;

void AtribHuge(Huge H, Huge X) {
  int i;
  for (i = 0; i <= X[0]; ++i) {
    H[i] = X[i];
  }
}

void AtribValue(Huge H, unsigned long X) {
  H[0] = 0;
  while (X) {
      ++H[0];
      H[H[0]] = X % 10;
      X /= 10;
  }
}

void MultHuge(Huge A, Huge B, Huge C)
/* C <- A x B */
{ int i,j,T=0;

  C[0]=A[0]+B[0]-1;
  for (i=1;i<=A[0]+B[0];) C[i++]=0;
  for (i=1;i<=A[0];i++)
    for (j=1;j<=B[0];j++)
      C[i+j-1]+=A[i]*B[j];
  for (i=1;i<=C[0];i++)
    { T=(C[i]+=T)/10;
      C[i]%=10;
    }
  if (T) C[++C[0]]=T;
}

void WriteHuge(Huge X)
{
  int i;
  for (i=X[0]; i; i--)
    cout<<X[i];
}

int main()
{
    cin>>k;
    Huge a,b,c;
    AtribValue(a,55);
    AtribValue(b,55);
    for(int i=2; i<k; ++i) {
        MultHuge(a,b,c);
        AtribHuge(a,c);
    }
    AtribValue(b,36);
    MultHuge(a,b,c);
    WriteHuge(c);
    return 0;
}
