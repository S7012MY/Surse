#include <iostream>
using namespace std;

int n,m,rez,x;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            cin>>x;
            if(x!=i) ++rez;
        }
    cout<<rez;
    return 0;
}
