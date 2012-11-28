#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double d,v1,h1,g1,v2,h2,g2,v3;

int main()
{
    ifstream f("balulbobocilor.in");
    ofstream g("balulbobocilor.out");
    f>>d>>v1>>h1>>g1>>v2>>h2>>g2>>v3;
    g<<fixed<<setprecision(6)<<(d*v3)/(v1+v2);
    return 0;
}
