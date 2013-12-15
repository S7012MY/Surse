#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n,rez;

int main()
{
    ifstream f("serviciu.in");
    ofstream g("serviciu.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        int a,b;
        f>>a>>b;
        if(a>b) swap(b,a);
        rez=max(rez,min(b-a,2*n-b+a));
    }
    g<<rez;
    return 0;
}
