#include <iostream>
#include <algorithm>
#define DN 100005
using namespace std;

int n,x,v[2][DN],rez;

int main()
{
    cin>>n>>x;
    for(int i=1; i<=n; ++i) cin>>v[0][i];
    for(int i=1; i<=n; ++i) cin>>v[1][i];
    sort(v[0]+1,v[0]+n+1);
    sort(v[1]+1,v[1]+n+1);
    int j=1,ok=1;
    for(int i=n; i;--i){
        for(;j<=n&& v[0][i]+v[1][j]<x&&ok;++j);
		if(j==n&&v[0][i]+v[1][j]<x) ok=0;
		if(ok){
			if(v[0][i]+v[1][j]>=x&&j<=n){
				++rez;
				++j;
			}
		}
	}
    cout<<1<<' '<<rez;
    return 0;
}
