#include <iostream>
#include <iomanip>
#include <fstream>
#define DN 30005
using namespace std;

int n,l,u,st,dr,dq[DN];
double s[DN],t[DN],el[DN];

void push(int poz) {
    for(;st<=dr && el[dq[dr]]>=el[poz];--dr);
    dq[++dr]=poz;
}

void erase(int poz) {
    for(;dq[st]<=poz;++st);
}

bool check(double r) {
    st=0,dr=-1;
    for(int i=1; i<=n; ++i) el[i]=el[i-1]+s[i]-r*t[i];
    if(el[l]>=0) return 1;
    for(int i=l+1; i<=n; ++i) {
        push(i-l);
        if(i-u-1>0) erase(i-u-1);
        if(el[i]-el[dq[st]]>=0) return 1;
    }
    return 0;
}

int main()
{
    ifstream f("secv3.in");
    ofstream g("secv3.out");
    f>>n>>l>>u;
    for(int i=1; i<=n; ++i) f>>s[i];
    for(int i=1; i<=n; ++i) f>>t[i];
    double ls=0,ld=15000000,m;
    for(int i=1; i<=100; ++i) {
        m=(ls+ld)*0.5;
        if(check(m)) ls=m;
        else ld=m;
    }
    g<<fixed<<setprecision(12)<<ls;
    return 0;
}
