#include <iostream>
#include <iomanip>
#include <cmath>
#define DN 1005
#define eps 1e-9
using namespace std;

int n;
double a,v[DN],lst;

int main()
{
    cin>>n>>v[1];
    double ls=1,ld=(1<<31)-1,m;
    for(;abs(ls-ld)>eps;) {
        m=((double)ls+ld)/2.0;
        v[2]=m/100.0;
       // cout<<ls<<' '<<ld<<'\n';
        int i;
        for(i=3; i<=n; ++i) {
            v[i]=2.0*v[i-1]-v[i-2]+2.0;
            if(v[i]<0) break;
        }
        if(i>n) ld=m,lst=v[n];
        else ls=m;
    }
    cout<<fixed<<setprecision(2)<<lst;
    return 0;
}
