#include <iostream>
#include <fstream>
using namespace std;

int t,n,a,b;

int main()
{
    ifstream f("jimmy.in");
    ofstream g("jimmy.out");
    for(f>>t;t;--t) {
        f>>n;
        g<<n/2<<'\n';
        for(int i=1; i<=3*n/2; ++i) f>>a>>b;
    }
    return 0;
}
