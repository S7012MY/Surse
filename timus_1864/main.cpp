#include <iostream>
#define DN 105
using namespace std;

int n;
double v[DN],s;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i],s+=v[i];
    s=s/(n+1);
    for(int i=1; i<=n; ++i) v[i]-=s;
    s=0;
    for(int i=1; i<=n; ++i) if(v[i]>0) s+=v[i];
    for(int i=1; i<=n; ++i)
        if(v[i]>0) cout<<(int)((v[i]*100)/s+1e-6)<<' ';
        else cout<<"0 ";
    return 0;
}
