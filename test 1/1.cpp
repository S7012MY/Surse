#include <iostream>
#include <fstream>
#include <cmath>
#define EPS 1e-4
#define EBUN 1e-5
using namespace std;

int n;
double a[10];

double pt(double x, int p) {
    double ret=1;
    for(int i=1; i<=p; ++i) ret*=x;
    return ret;
}

double fa(double i) {
    double rez=0;
    for(int j=n; j>=0; --j) {
        rez+=(a[j]*pt(i,j));
    }
    return rez;
}

int main()
{
    ifstream f("radacina.in");
    ofstream g("radacina.out");
    f>>n;
    for(int i=0; i<=n; ++i) {
        f>>a[i];
    }
    int semn=0,lsemn=0;
    double i,s1,s2,start=0;
    s1=s2=0;
    int ok=0;
    for(;!ok;start+=EBUN) {
        for(i=-20+EPS+start; i<20; i+=EPS) {
            if(fa(i-EPS)*fa(i+EPS)<0) {
                s1=i-EPS;
                s2=i+EPS;
                ok=1;
               // cout<<s1<<' '<<s2;
                break;
            }
        }
    }

    for(i=s1;i<=s2; i+=EBUN) {
        double rez=fa(i);
        //cout<<i<<' '<<rez<<'\n';
        if(fa(i-EBUN)*fa(i)<0) {
            g<<i;
            return 0;
        }
        if(rez+EBUN>=0 && rez-EBUN<=0) {
            g<<i;
            return 0;
        }
    }
    return 0;
}