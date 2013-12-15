#include <iostream>
#include <cmath>
using namespace std;

int n,m,mx,nrm;
double a[55],b[55];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    cin>>m;
    for(int i=1; i<=m; ++i) cin>>b[i];
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) if(floor(b[i]/a[j])==ceil(b[i]/a[j])) {
        if(b[i]/a[j]>mx) {
            mx=b[i]/a[j];
            nrm=1;
        }else if (b[i]/a[j]==mx) ++nrm;
    }
    cout<<nrm;
    return 0;
}
