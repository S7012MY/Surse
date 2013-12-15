#include <iostream>
#include <set>
#define DN 305
using namespace std;

int n,m[DN][DN];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n+1; ++j) cin>>m[i][j];
    return 0;
}
