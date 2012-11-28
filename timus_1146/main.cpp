#include <iostream>
using namespace std;

int n,m[105][105],sp[105][105],bst;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        cin>>m[i][j];
        sp[i][j]=m[i][j]+sp[i-1][j];
    }
    bst=m[1][1];
    for(int l1=1; l1<=n; ++l1) for(int l2=l1; l2<=n; ++l2) {
        int sm=sp[l2][1]-sp[l1-1][1];
        bst=max(bst,sm);
        for(int i=2; i<=n; ++i) {
            sm=max(sm+sp[l2][i]-sp[l1-1][i],sp[l2][i]-sp[l1-1][i]);
            bst=max(bst,sm);
        }
    }
    cout<<bst;
    return 0;
}
