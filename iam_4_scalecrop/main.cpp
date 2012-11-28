#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

double a,b,x,y;
double ra,rb,proc,ra2,rb2;

int main()
{
    ifstream f("scalecrop.in");
    ofstream g("scalecrop.out");
    f>>a>>b>>x>>y;

        ra=a;
        proc=(a*100.0)/x;
        rb=y*proc;
        rb/=100.0;

        rb2=b;
        proc=(b*100.0)/y;
        ra2=x*proc;
        ra2/=100.0;
    if(ra2<a || rb2<b) g<<fixed<<setprecision(2)<<ra<<' '<<rb;
    else g<<fixed<<setprecision(2)<<ra2<<' '<<rb2;
    return 0;
}
