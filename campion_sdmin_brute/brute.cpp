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
    scanf("%d %d",&n,&sus);
    for(int i=1; i<=n; ++i) scanf("%d %d %d",&seg[i].xs,&seg[i].xd,&seg[i].y);
    double left=0,right=100,p,bs=999999999;
    for(double i=left; i<=right; i+=EPS) {
        if(msum(i)<bs) {
            bs=msum(i);
            p=i;
        }
    }
   // fprintf(stderr,"%.6lf %.6lf",bs,p);
    FILE *f=fopen("sdmin.out","r");
    double r1,r2;
    fscanf(f,"%lf %lf",&r1,&r2);
    if(fabs(r1-bs)>1e-4 || fabs(r2-p)>1e-4) {
        fprintf(stderr,"GRESIT\n");
        while(1);
    }
    fprintf(stderr,"CORECT\n");
    return 0;
}
