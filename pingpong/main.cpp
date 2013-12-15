#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

double p1,p2,p3,p4,p5,q1,q2,q3,q4,q5,p;
double psa,psb;//probabilitatea de a castiga un punct daca serveste a sau daca serveste b
double pset[15][15],dif[2][10];
double pwsa,pwsb;

double faSet(int prim) {
    memset(pset,0,sizeof(pset));
    double rez=0;
    pset[0][0]=1;
    for(int i=0; i<11; ++i) {
        for(int j=0; j<11; ++j) {
            int s=j+i,sc=2;
            if(i<=10 && j<=10) {
                if(s%4<2) sc=prim;
                else sc=!prim;
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
    memset(dif,0,sizeof(dif));
    dif[0][0+3]=pset[10][10];
    for(int i=1; i<=60000; ++i) {
        int sc=2,c=i&1,p=(i&1)^1;
        if(i&1) sc=prim;
        else sc=!prim;
        double prob=psa;
        if(!sc) prob=psb;
        //cerr<<prob<<'\n';
       // cerr<<dif[c][0+3]<<' ';
        //memset(dif[c],0,sizeof(dif));
        if(!(i&1)) {
            dif[c][0  +3]=dif[p][1  +3]*(1-prob);
            dif[c][0  +3]+=dif[p][-1 +3]*prob;
            dif[c][2  +3]+=dif[p][1  +3]*prob;
            dif[c][-2 +3]+=dif[p][-1 +3]*(1-prob);
        }else {
            //cerr<<i<<' '<<dif[p][0+3]<<'\n';
            dif[c][1  +3]=dif[p][0  +3]*prob;
            dif[c][-1 +3]=dif[p][0  +3]*(1-prob);
        }
       // for(int j=-2; j<=2; ++j) cerr<<dif[c][j+3]<<' ';
        //cerr<<'\n';
        //if(i>20) while(1);
    }
    //for(int j=-2; j<=2; ++j) cerr<<dif[0][j+3]<<' ';
        //cerr<<'\n';
    for(int i=0; i<10; ++i) rez+=pset[11][i];
    rez+=dif[0][2+3];
    //cout<<rez<<'\n';
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
    printf("%.9lf",(faMeci(1)+faMeci(0))*0.5);
    return 0;
}
