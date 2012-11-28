#include <iostream>
using namespace std;

const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int main()
{
    int n,ls,ld,a[55][55],s=0;
    cin>>n;
    ls=1;ld=n*n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if((i+j)&1) {
                a[i][j]=ld;
                --ld;
            }else {
                a[i][j]=ls;
                ++ls;
            }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) for(int d=0; d<4; ++d) s=max(s,a[i][j]+a[i+dx[d]][j+dy[d]]);
    cout<<s<<'\n';
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) cout<<a[i][j]<<' ';
        cout<<'\n';
     }
    return 0;
}
