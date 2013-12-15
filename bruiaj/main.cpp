#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cmath>
#define PI 3.141592653589793238
using namespace std;

double ax,ay,bx,by,cx,cy,ix,iy;
double a,b,c;
const double dx[]={0.0001,0,-0.0001, 0};
const double dy[]={0,0.0001, 0,-0.0001};

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

double getdist(double ix,double iy) {
    return min(plin(ix,iy,ax,ay,bx,by),min(plin(ix,iy,cx,cy,bx,by),plin(ix,iy,ax,ay,cx,cy)));
}

bool isinside(double px,double py) {
    double abc=arie(ax,ay,bx,by,cx,cy);
    double pab=arie(ax,ay,bx,by,px,py);
    double pbc=arie(px,py,bx,by,cx,cy);
    double pac=arie(ax,ay,px,py,cx,cy);
    return abc==pab+pbc+pac;
}

int main()
{
    srand(time(NULL));
    ifstream f("bruiaj.in");
    ofstream g("bruiaj.out");
    f>>ax>>ay>>bx>>by>>cx>>cy;
    ix=(ax+bx+cx)/3.0; iy=(ay+by+cy)/3.0;
    double err=1000;//coord maxima a punctelor
    //cout<<ix<<' '<<iy;
    for(int i=1; i<=5000; ++i) {
        bool ni=1;//n-am gasit o distanta mai buna
        double dst=getdist(ix,iy);
        for(int r=0; r<40; ++r) {
            double ra=rand()/(double)(1<<15)*2*PI;
            double iix=ix+err*sin(ra);
            double iiy=iy+err*cos(ra);
            if(dst<getdist(iix,iiy)) {
                ix=iix; iy=iiy;
                ni=0;
                break;
            }
            if(ni) err*=(9.0/10.0);
        }
    }
    g<<ix<<' '<<iy<<'\n'<<getdist(ix,iy);
    return 0;
}
