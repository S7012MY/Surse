#include <iostream>
#define DN 105
using namespace std;

int n,k,r[DN];

int main()
{
    cin>>n>>k;
    n=2*n+1;
    for(int i=1; i<=n; ++i)
        cin>>r[i];
    for(int i=2; i<n;++i)
        if(r[i]>r[i-1] && r[i]>r[i+1] && k) {
            --r[i];
            --k;
        }
    for(int i=1; i<=n; ++i) cout<<r[i]<<' ';
    return 0;
}
