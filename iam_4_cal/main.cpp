#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int sx,sy,s,n,rez;

int mht(int x1,int y1, int x2, int y2) {
    return abs(x2-x1)+abs(y2-y1);
}

int main()
{
    ifstream f("cal.in");
    ofstream g("cal.out");
    f>>sx>>sy>>s>>n;
    sx+=100000000; sy+=100000000;
    for(int i=1; i<=n; ++i) {
        int a,b;
        f>>a>>b;
        a+=100000000; b+=100000000;
        if(mht(sx,sy,a,b)==s) ++rez;
    }
    g<<rez;
    return 0;
}
