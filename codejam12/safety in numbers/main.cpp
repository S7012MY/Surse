#include <iostream>
#include <iomanip>
#include <fstream>
#define EPS 1e-6
#define DN 205
//Ji+X*Yi
using namespace std;

int t,n;
double j[DN],sum;

int main()
{
    ifstream f("input.in");
    ofstream g("output.out");
    f>>t;
    for(int k=1; k<=t; ++k) {
        f>>n;
        sum=0;
        for(int i=1; i<=n; ++i) {
            f>>j[i];
            sum+=j[i];
        }
        for(int i=1; i<=n; ++i) j[i]/=(double)sum;
        for(int i=1; i<=n; ++i) j[i]=max(0.0,2.0/n-j[i]);
        sum=0;
        for(int i=1; i<=n; ++i) sum+=j[i];
        for(int i=1; i<=n; ++i) j[i]/=(double)sum;
        g<<"Case #"<<k<<": ";
        for(int i=1; i<=n; ++i) {
            g<<fixed<<setprecision(6)<<j[i]*100.0<<' ';
        }
        g<<'\n';
    }
    return 0;
}
