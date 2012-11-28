#include <cstdio>
#include <cmath>
#define DN 505
#define EPS 1e-5
#define deb(n) fprintf(stderr,"%lf ",(n));
#define debnl fprintf(stderr,"\n");

struct segm {
    int xs,xd,y;
} seg[DN];

int sus,n;

double distp(double x1,double y1, double x2, double y2) {
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}

double msum(double k) {
    double sd=0;
    for(int i=1; i<=n; ++i)
        if(seg[i].xs>k) sd+=distp(seg[i].xs,seg[i].y,k,sus);
        else if(seg[i].xs<=k && k<=seg[i].xd) sd+=(double)sus-(double)seg[i].y;
        else sd+=distp(seg[i].xd,seg[i].y,k,sus);
    return sd;
}

int main()
{
    freopen("sdmin.in","r",stdin);
    freopen("sdmin.out","w",stdout);
    scanf("%d %d",&n,&sus);
    for(int i=1; i<=n; ++i) scanf("%d %d %d",&seg[i].xs,&seg[i].xd,&seg[i].y);
    //cautare ternara
    double left=-2000001,right=2000001;
    for(;right-left>EPS;) {
        double lt=(2.0*left + right)/3.0,rt=(left + 2.0*right)/3.0;
        double flt=msum(lt),drt=msum(rt);
        if(flt<drt) right=rt;
        else left=lt;
    }
    printf("%.6lf %.6lf",msum(left),left);
    return 0;
}
