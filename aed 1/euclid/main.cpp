#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    for(int c;b;c=a%b,a=b,b=c);
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    for(f>>t;t;--t) {
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
    return 0;
}
