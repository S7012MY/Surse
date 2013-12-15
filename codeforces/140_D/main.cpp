#include <iostream>
#define DN 100005
using namespace std;

int n,v,m;
long long sum;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v;
        sum+=v;
    }
    cin>>m;
    for(int i=1; i<=m; ++i) {
        cin>>v;
        cout<<sum-min(v,n-1)<<' ';
    }
    return 0;
}
