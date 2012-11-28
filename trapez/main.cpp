#include <iostream>
#include <fstream>
#include <algorithm>
#define inf (1<<30)
#define DN 1005
using namespace std;

int n,sz=-1;
double pnt[DN*DN],x[DN],y[DN];

int main()
{
    ifstream f("trapez.in");
    ofstream g("trapez.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>x[i]>>y[i];
    for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) {
        if(x[j]-x[i]==0) pnt[++sz]=inf;
        else pnt[++sz]=(y[j]-y[i])/(x[j]-x[i]);
    }
    sort(pnt,pnt+sz+1);
    int eg=1,rez=0;
    for(int i=0; i<sz; ++i) {
        if(pnt[i]==pnt[i+1]) ++eg;
        else {
            rez+=(eg*(eg-1))/2;
            eg=1;
        }
    }
    g<<rez;
    return 0;
}
