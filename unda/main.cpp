#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#define EPS 1e-6
#define INF 1e+6
#define DN 2005
#define xx first
#define yy second
using namespace std;

typedef pair<double, double> per;

int n,x[DN],y[DN];
vector<per> sc,su;
vector<int> semn;

int edr(double a, double b, double c, double x, double y) {
    double d=a*x+b*y+c;
    if(d<-EPS) return -1;
    if(d>EPS) return 1;
    return 0;
}

double faec(double x1, double y1,double x2, double y2, double &a, double &b, double &c) {
    a=y1-y2;
    b=x2-x1;
    c=x1*y2-x2*y1;
}

per inters(double a1, double b1,double c1, per p1, per p2) {
    double a2,b2,c2;
    faec(p1.xx,p1.yy,p2.xx,p2.yy,a2,b2,c2);
    double det=a1*b2-a2*b1;
    if(fabs(det)<EPS) return make_pair(-INF,-INF);
    double x,y;
    x=(b1*c2-b2*c1)/det;
    y=(a2*c1-a1*c2)/det;
    return make_pair(x,y);
}

double solve() {
    sc.clear(); semn.clear();
    sc.push_back(make_pair(-INF,-INF));
    sc.push_back(make_pair(-INF,INF));
    sc.push_back(make_pair(INF,INF));
    sc.push_back(make_pair(INF,-INF));

    double a,b,c;
    for(int i=0; i<n; ++i) {
        su.clear();
        semn.resize(sc.size()+1);
        faec(x[i],y[i],x[i+1],y[i+1],a,b,c);

        for(int j=0; j<sc.size(); ++j)
            semn[j]=edr(a,b,c,sc[j].xx,sc[j].yy);
        semn[sc.size()]=semn[0];
        for(int j=0; j<sc.size(); ++j) {
            per nxt=sc[(j+1)%(int)sc.size()];
            if(semn[j]<=0 && semn[j+1]<=0)
                su.push_back(nxt);
            if(semn[j]<=0 && semn[j+1]>0)
                su.push_back(inters(a,b,c,sc[j],nxt));
            if(semn[j]>0 && semn[j+1]>0) continue;
            if(semn[j]>0 && semn[j+1]<=0) {
                su.push_back(inters(a,b,c,sc[j],nxt));
                su.push_back(nxt);
            }
        }
        sc=su;
    }
    sc.push_back(sc[0]);
    double ret=0;
    for(int i=0; i<sc.size()-1; ++i)
        ret+=sc[i].xx*sc[i+1].yy-sc[i+1].xx*sc[i].yy;
    return fabs(ret*0.5);
}

int main()
{
    ifstream f("camera.in");
    ofstream g("camera.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>x[i]>>y[i];
    x[n]=x[0]; y[n]=y[0];
    double rez=solve();
    if(fabs(rez)<EPS) {
        for(int i=0,j=n;i<j;++i,--j) {
            swap(x[i],x[j]);
            swap(y[i],y[j]);
        }
        rez=solve();
    }
    g<<fixed<<setprecision(2)<<rez;
    return 0;
}
