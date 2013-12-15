#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

double ax,ay,bx,by,cx,cy,ix,iy;
double a,b,c;

double dist(double ax, double ay, double bx,double by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

double arie(double ax, double ay, double bx,double by,double cx,double cy) {
    return fabs(ax*by+ay*cx+bx*cy-ax*cy-ay*bx-cx*by)*0.5;
}

double plin(double px,double py,double ax, double ay, double bx,double by) {
    double ar=arie(px,py,ax,ay,bx,by),b=dist(ax,ay,bx,by);
    return (2.0*ar)/b;
}

int main()
{
    ifstream f("bruiaj.in");
    ofstream g("bruiaj.out");
    f>>ax>>ay>>bx>>by>>cx>>cy;
    a=dist(bx,by,cx,cy);
    b=dist(ax,ay,cx,cy);
    c=dist(ax,ay,bx,by);
    ix=(a*ax+b*bx+c*cx)/(a+b+c);
    iy=(a*ay+b*by+c*cy)/(a+b+c);
g<<fixed<<setprecision(8);
    g<<ix<<' '<<iy<<'\n'<<min(plin(ix,iy,ax,ay,bx,by),min(plin(ix,iy,cx,cy,bx,by),plin(ix,iy,ax,ay,cx,cy)));
    return 0;
}
