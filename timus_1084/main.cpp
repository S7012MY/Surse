#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265
using namespace std;

double l,r;

int main()
{
    cout<<fixed<<setprecision(3);
    cin>>l>>r;
    if(r+r>=l*sqrt(2.0)) {
        cout<<l*l;
        return 0;
    }else if(r<=l*0.5) {
        cout<<PI*r*r;
        return 0;
    }
    double halflat=l*0.5;
    double a=sqrt(r*r-halflat*halflat);
    double alpha=asin(a/r);
    double beta=(2.0*PI-8.0*alpha)/4.0;
    double at=2*a*l*0.25;
    double ac=r*r*beta*0.5;
    cout<<at*4.0+ac*4.0;
    return 0;
}
