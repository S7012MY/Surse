#include <iostream>
#include <iomanip>
using namespace std;

int n;
double t,s,si;
double dif,ramas;

int main()
{
    cout<<fixed<<setprecision(10);
    cin>>n>>t>>s;
    for(int i=1; i<=n; ++i) {
        cin>>si;
        dif=si-s;
        ramas=t-dif;
        cout<<s+ramas/2+dif<<'\n';
    }
    return 0;
}
