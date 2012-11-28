#include <iostream>
#define DN 1005
using namespace std;

int n,m,v[DN];

int main()
{
    cin>>n>>m;
    m=m%n;
    for(int i=0; i<n; ++i) cin>>v[i];
    for(int i=0; i<10; ++i) cout<<v[(i+m)%n];
    return 0;
}
