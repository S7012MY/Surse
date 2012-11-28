#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a,b;
    for(cin>>a>>b;a!=-1&&b!=-1;cin>>a>>b) {
       // cout<<fixed<<setprecision(8)<<(double)a/b<<' '<<(double)1000/37<<'\n';
        if(a*37==b*1000) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}
