#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#define EPS 1e-6
#define INF 1e+6
#define DN 105
#define xx first
#define yy second
using namespace std;

typedef pair<double, double> per;

int n,x[DN],y[DN],dimx,dimy;
vector<per> sc,su;
vector<int> semn;
multiset<pair<double,int> ,greater<pair<double,int> > > s;

int edr(double a, double b, double c, double x, double y) {
    double d=a*x+b*y+c;
    if(d<-EPS) return -1;
    if(d>EPS) return 1;
    return 0;
}

void faec(double x1, double y1,double x2, double y2, double &a, double &b, double &c) {
    a=y1-y2;
    b=x2-x1;
    c=x1*y2-x2*y1;
}

void fam(double x1, double y1,double x2, double y2, double &a, double &b, double &c) {
    double xm=(x1+x2)*0.5, ym=(y1+y2)*0.5;
   // cout<<x1<<' '<<xm<<' '<<x2<<' '<<y1<<' '<<ym<<' '<<y2<<'\n';
    a=x1-x2;
    b=y1-y2;
    c=-a*xm-b*ym;
}

per inters(double a1, double b1,double c1, per p1, per p2) {
    double a2,b2,c2;
    faec(p1.xx,p1.yy,p2.xx,p2.yy,a2,b2,c2);
    double det=a1*b2-a2*b1;
    if(fabs(det)<EPS) return make_pair(0,0);
    double x,y;
    x=(b1*c2-b2*c1)/det;
    y=(a2*c1-a1*c2)/det;
    return make_pair(x,y);
}

double solve(int p) {
    sc.clear(); semn.clear();
    sc.push_back(make_pair(0,0));
    sc.push_back(make_pair(0,dimy));
    sc.push_back(make_pair(dimx,dimy));
    sc.push_back(make_pair(dimx,0));

    double a,b,c;
    for(int i=0; i<n; ++i) if(i!=p) {
        su.clear();
        semn.resize(sc.size()+1);
        fam(x[i],y[i],x[p],y[p],a,b,c);
	//cout<<i<<' '<<p<<' '<<a<<' '<<b<<' '<<c<<'\n';
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
   // for(int i=0; i<sc.size(); ++i) cout<<sc[i].xx<<' '<<sc[i].yy<<'\n';
    //cout<<'\n';
    double ret=0;
    for(int i=0; i<sc.size()-1; ++i)
        ret+=sc[i].xx*sc[i+1].yy-sc[i+1].xx*sc[i].yy;
    return fabs(ret*0.5);
}

int main()
{
    for(;;) {
		s.clear();
		scanf("%d %d",&dimx,&dimy);
        if(dimx==0 && dimy==0) break;
		scanf("%d",&n);
        for(int i=0; i<n; ++i) scanf("%d %d",&x[i],&y[i]);
        x[n]=x[0]; y[n]=y[0];
        for(int p=0; p<n; ++p) {
            double rez=solve(p);
            if(fabs(rez)<EPS) {
                for(int i=0,j=n;i<j;++i,--j) {
                    swap(x[i],x[j]);
                    swap(y[i],y[j]);
                }
                rez=solve(p);
            }
			s.insert(make_pair(rez,p));
        }
		for(set<pair<double,int> >::iterator is=s.begin();is!=s.end(); ++is) printf("%03d%14.2lf\n", is->yy+1, is->xx);
		printf("\n");
    }
    return 0;
}
