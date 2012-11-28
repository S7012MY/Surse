#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS 1e-13
using namespace std;

double h,H,l,m;

double cd(double L) {
    return (H*L)/(2.0*sqrt(L*L+h*h))-L;
}

int main()
{
    cin>>h>>H>>l;
    double ls=0,ld=l,rez=0;
    for(;ld-ls>=EPS;) {
        //cout<<setprecision(13)<<ls<<' '<<ld<<'\n';
        double s=(2*ls+ld)/3.0,d=(ls+2*ld)/3.0;
        if(cd(s)>cd(d)) ld=d;
        else ls=s;
    }
    cout<<fixed<<setprecision(5)<<cd(ls);
    return 0;
}
