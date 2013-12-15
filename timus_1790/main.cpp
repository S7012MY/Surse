#include <iostream>
#include <bitset>
#define DN 100005
using namespace std;

int n,m,x;
bitset<DN> prec,act;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i) prec[i]=1;
    for(int i=0; i<m; ++i) {
      cin>>x;
      prec[x]=0;
      act[1]=prec[0];
      act[n]=prec[n-1];
      for(int i=2; i<n; ++i) act[i]=prec[i-1]|prec[i+1];
      prec=act;
    }
    if(prec.count()==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
