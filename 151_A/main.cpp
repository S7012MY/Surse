#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,sdif,x[100005];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    for(int i=2; i<=n; ++i) {
        sdif+=abs(x[i]-x[i-1]);
    }
    if(sdif&1) cout<<n-1;
    else cout<<n;
    return 0;
}
