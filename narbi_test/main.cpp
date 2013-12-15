#include <iostream>
#include <fstream>
#define LL long long
using namespace std;

int n,k,x1,x2,rez[75000];
LL r;

int count(long n) {
    int num = 0;
    if (n)
        do num++; while (n &= n - 1);
    return num;
}

int main()
{
    ifstream f("narbi.in");
    ofstream g("narbi.out");
    f>>n>>k>>x2;
    for(int i=1; i<=66000; ++i) rez[i]=count(i);
    for(int j=1; j<=n; ++j) {
        for(int i=x1+1; i<=x2; ++i)
            r+=rez[i&((1<<16)-1)]+rez[i>>16];
        x1=x2;
        x2+=(r%16)+1;
        if(n-j<k) g<<r<<'\n';
    }
    return 0;
}
