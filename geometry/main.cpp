#include <iostream>
#include <fstream>
#include <cmath>
#define DN 505
using namespace std;

double n,X1[DN],Y1[DN],x2[DN],y2[DN];

double dist(double X1,double Y1, double x2, double y2) {
    return sqrt((X1-x2)*(X1-x2)+(Y1-y2)*(Y1-y2));
}

int inters(int i,int j) {
    //http://en.wikipedia.org/wiki/Line-line_intersection
    double num=(X1[i]-x2[i])*(Y1[j]-y2[j])-(Y1[i]-y2[i])*(X1[j]-x2[j]);
    //drepte paralele
    if(fabs(num)<1e-9) {
        if(fabs(dist(X1[i],Y1[i],X1[j],Y1[j])+dist(X1[i],Y1[i],x2[j],y2[j])-dist(X1[j],Y1[j],x2[j],y2[j]))<1e-9 ||
           fabs(dist(x2[i],y2[i],X1[j],Y1[j])+dist(x2[i],y2[i],x2[j],y2[j])-dist(X1[j],Y1[j],x2[j],y2[j]))<1e-9)
            return 1;
        return 0;
    }
    double x=(X1[i]*y2[i]-Y1[i]*x2[i])*(X1[j]-x2[j])-(X1[i]-x2[i])*(X1[j]*y2[j]-Y1[j]*x2[j]);
    double y=(X1[i]*y2[i]-Y1[i]*x2[i])*(Y1[j]-y2[j])-(Y1[i]-y2[i])*(X1[j]*y2[j]-Y1[j]*x2[j]);
    x/=num; y/=num;

    if(x<min(X1[i],x2[i]) || x>max(X1[i],x2[i])) return 0;
    if(x<min(X1[j],x2[j]) || x>max(X1[j],x2[j])) return 0;
    if(y<min(Y1[i],y2[i]) || y>max(Y1[i],y2[i])) return 0;
    if(y<min(Y1[j],y2[j]) || y>max(Y1[j],y2[j])) return 0;
    return 1;
}

int main()
{
    ifstream f("geometry.in");
    ofstream g("geometry.out");
    f>>n;
    int rez=0;
    for(int i=0; i<n; ++i) f>>X1[i]>>Y1[i]>>x2[i]>>y2[i];
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j)
            rez+=inters(i,j);
    }
    g<<rez;
    return 0;
}
