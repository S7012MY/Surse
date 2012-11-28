#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("chatnoir.in");
    ofstream g("chatnoir.out");
    int t,n,m,x0,y0;
    for(f>>t;t--;) {
        f>>n>>m>>x0>>y0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) if(x0==i && y0==j) cout<<"x";
            else cout<<"0";
            cout<<endl;
        }
        cout<<endl;
        if(n/2<x0 || m/2<y0) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
