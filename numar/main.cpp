#include <fstream>
#include <iostream>
using namespace std;

int n;

int gauss(int n) {
    if(n>=0) return n*(n+1)/2;
    else return n*(n-1)/-2;
}

int sum(int a,int b) {
    int ret=0;
    for(int i=a; i<=b; ++i) ret+=i;
    return ret;
}

int main()
{
    ifstream f("numar.in");
    ofstream g("numar.out");
    f>>n;
    for(int i=1; i*i<=n; ++i) if(0==n%i) {
        int sum=n/i;
        g<<2*i<<' ';
    }
    return 0;
}
