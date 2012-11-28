#include <iostream>
#define DN 10005
using namespace std;

int n,m,v[DN],kmin=DN,ok[DN]={2,1};

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        cin>>v[i];
        kmin=min(kmin,v[i]);
    }
    for(int i=1; i<=m; ++i) v[i]/=kmin;
    n/=kmin;
    for(int i=2; i<=n; ++i) for(int j=1; j<=m; ++j) if(i-v[j]>=0) ok[i]=max(ok[i],(ok[i-v[j]]==2)?1:2);
    cout<<ok[n];
    return 0;
}
