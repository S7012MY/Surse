#include <iostream>
#include <iomanip>
#define DN 100005
using namespace std;

double rez,n,m;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        rez+=(1-rez/n);
    }
    cout<<fixed<<setprecision(9)<<rez;
    return 0;
}
