#include <iostream>
#include <fstream>
#define DN 20005
using namespace std;

int nr[DN],a,b,ok;

int main()
{
    ifstream f("patrat.in");
    ofstream g("patrat.out");
    f>>a>>b;
    for(int i=1; i*i<=b; ++i) for(int j=i+1; j*j<=b; ++j) if(i*i+j*j<DN) ++nr[i*i+j*j];
    for(int i=a; i<=b; ++i) if(nr[i]>1) g<<i<<'\n',ok=1;
    if(!ok) g<<"0";
    return 0;
}
