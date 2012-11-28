#include <iostream>
#define DN 105
using namespace std;

int n,m,a[DN][DN],r[DN][DN],cnt;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin>>a[i][j];
    for(int i=1; i<n; i+=2) for(int j=1; j<m; j+=2) {
        if(a[i][j]==a[i+1][j] || a[i][j+1]==a[i+1][j+1]) {
            r[i][j]=r[i][j+1]=++cnt;
            r[i+1][j]=r[i+1][j+1]=++cnt;
        }else {
            r[i][j]=r[i+1][j]=++cnt;
            r[i][j+1]=r[i+1][j+1]=++cnt;
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cout<<r[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
