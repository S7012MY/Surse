#include <cstdio>
#include <cmath>

struct p{
    double c[10];
} A,B,C;

double r;

double dist(p a, p b) {
    double sum=0;
    for(int i=1; i<=8; ++i) sum+=((a.c[i]-b.c[i])*(a.c[i]-b.c[i]));
    return sqrt(sum);
}

double acos1(double x) {
    if(x > 1)
        x = 1;
    if(x < -1)
        x = -1;
    return acos(x);
}

int main()
{
    for(int i=1; i<=8; ++i) scanf("%lf",&A.c[i]);
    for(int i=1; i<=8; ++i) scanf("%lf",&B.c[i]);
    for(int i=1; i<=8; ++i) scanf("%lf",&C.c[i]);
    scanf("%lf",&r);
    double AC=dist(A,C),BC=dist(B,C),AB=dist(A,B);
    double p=(AC+BC+AB)/2.0;
    double ABC=sqrt(p*(p-AB)*(p-BC)*(p-AC));
    double d=(2.0*ABC)/AB;

    double Aa=sqrt(AC*AC-r*r),Bb=sqrt(BC*BC-r*r);
    double ACa=acos1((Aa*Aa-r*r-AC*AC)/(-2.0*AC*r));
    double BCb=acos1((Bb*Bb-r*r-BC*BC)/(-2.0*BC*r));
    double ACB=acos1((AB*AB-AC*AC-BC*BC)/(-2.0*AC*BC));
    double aCb=ACB-ACa-BCb;
    double ab=aCb*r;
    //cout<<Aa<<' '<<ab<<' '<<Bb<<'\n';
    if(ab>0.0 && r>d)printf("%.2lf",Aa+ab+Bb);
    else printf("%.2lf",AB);
    return 0;
}
