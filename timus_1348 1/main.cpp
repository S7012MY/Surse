#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS 1e-6
using namespace std;

double xa,ya,xb,yb,xc,yc;
double lg;

double aria(double xa,double ya,double xb,double yb,double xc,double yc) {
    return fabs((xa*yb+xb*yc+xc*ya-xc*yb-xb*ya-xa*yc)*0.5);
}

double dist(double xa,double ya,double xb,double yb) {
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

int main()
{
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>lg;
    double ar=aria(xa,ya,xb,yb,xc,yc);
    double ab=dist(xa,ya,xb,yb),ac=dist(xc,yc,xa,ya),bc=dist(xc,yc,xb,yb);
    double rf=(ar*2.0)/ab;
    if(ab<EPS) {
        cout<<fixed<<setprecision(2)<<max(ac-lg,0.0)<<'\n'<<max(ac-lg,0.0);
        return 0;
    }
    if(bc*bc>ab*ab+ac*ac)
        //a obtuz
        rf=ac;
    if(ac*ac>ab*ac+bc*bc)
        //b obtuz
        rf=bc;
    cout<<fixed<<setprecision(2)<<max(rf-lg,0.0)<<'\n'<<max(max(ac,bc)-lg,0.0);
    return 0;
}
