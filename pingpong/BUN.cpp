#include <cstdio>
#include <cstring>
#include <cstdlib>

double p1,p2,p3,p4,p5,q1,q2,q3,q4,q5,p;
double psa,psb;//probabilitatea de a castiga un punct daca serveste a sau daca serveste b
double pset[1005][1005];
double pwsa,pwsb;

double faSet(int prim) {
    memset(pset,0,sizeof(pset));
    double rez=0;
    pset[0][0]=1;
    for(int i=0; i<1000; ++i) {
        for(int j=0; j<=1000; ++j) {
            int s=j+i,sc=2;
            if(i<=10 && j<=10) {
                if(s%4<2) sc=prim;
                else sc=!prim;
            }
            if((i>10 || j>10) && abs(i-j)<2) {
                if(s&1)  sc=!prim;
                else sc=prim;
            }
            if(sc==1) {
                pset[i+1][j]+=pset[i][j]*psa;
                pset[i][j+1]+=pset[i][j]*(1.0-psa);
            }else if(!sc){
                pset[i+1][j]+=pset[i][j]*psb;
                pset[i][j+1]+=pset[i][j]*(1.0-psb);
            }
        }
    }
    for(int i=0; i<10; ++i) rez+=pset[11][i];
    for(int i=12; i<=1000; ++i) rez+=pset[i][i-2];
    return rez;
}

double faMeci(int prim) {
    double rez=0;
    memset(pset,0,sizeof(pset));
    pset[0][0]=1;
    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) {
        int sc=!prim;
        if((i+j)%2==0) sc=prim;
        if(sc) {
            pset[i+1][j]+=pwsa*pset[i][j];
            pset[i][j+1]+=(1.0-pwsa)*pset[i][j];
        }else {
            pset[i+1][j]+=pwsb*pset[i][j];
            pset[i][j+1]+=(1.0-pwsb)*pset[i][j];
        }
    }
    for(int i=0; i<3; ++i) rez+=pset[3][i];
    return rez;
}

int main()
{
    freopen("pingpong.in","r",stdin);
    freopen("pingpong.out","w",stdout);
    scanf("%lf %lf %lf %lf %lf",&p1,&p2,&p3,&p4,&p5);
    scanf("%lf %lf %lf %lf %lf",&q1,&q2,&q3,&q4,&q5);
    scanf("%lf",&p);
    psa=p1+ (1-p1)*(1-q2)*p3+ (1-p1)*(1-q2)*(1-p3)*(1-q4)*p5+ (1-p1)*(1-q2)*(1-p3)*(1-q4)*(1-p5)*p;
    psb=(1-q1)*p2+ (1-q1)*(1-p2)*(1-q3)*p4+ (1-q1)*(1-p2)*(1-q3)*(1-p4)*(1-q5)*p;
    pwsb=faSet(0);
    pwsa=faSet(1);
    fprintf(stderr,"%.9lf %.9lf\n",psa,psb);
    fprintf(stderr,"%lf %lf\n",pwsa,pwsb);
    printf("%.3lf",(faMeci(1)+faMeci(0))*0.5);
    return 0;
}
