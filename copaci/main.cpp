#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n,nrm;
per p[DN];
double ar;

int cmmdc(int a, int b) {
    for(int c;b;c=a%b,a=b,b=c);
    return a;
}

int main()
{
    ifstream f("copaci.in");
    ofstream g("copaci.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
    p[n+1]=p[1];
    for(int i=1; i<=n; ++i) {
        ar+=(p[i].x*p[i+1].y)-(p[i].y*p[i+1].x);
        nrm+=cmmdc(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
    }
    ar/=2;
    ar=fabs(ar);
    g<<fixed<<setprecision(0)<<ar-nrm*0.5+1;
    return 0;
}
