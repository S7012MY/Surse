#include <iostream>
#include <algorithm>
#define DN 105
using namespace std;

int n,v[DN],rez;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>v[i];
    sort(v+1,v+n+1);
    for(;n>=4;) {
        if(v[1]+v[n-1]>2*v[2]) rez+=v[1]+2*v[2]+v[n];
        else  rez+=v[n]+v[n-1]+2*v[1];
        n-=2;
    }
    if(n==3) rez+=v[1]+v[2]+v[3];
    else if(n==2) rez+=v[2];
    else rez+=v[1];
    cout<<rez;
    return 0;
}
