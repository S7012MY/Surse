#include <iostream>
#include <fstream>
#define REST MOD
#define M MOD
#define put putere
using namespace std;

long long n,MOD;

long long putere (long long n, long long p) {
    if (p == 1) return n;
    if (p%2) return ( put(n,p-1) * n )%M;
    else return ( (put(n,p/2)%M) * (put(n,p/2)%M) ) %M;
}



int main()
{
    cin>>n>>MOD;
    cout<<(putere(3,n)-1+MOD)%MOD;
    return 0;
}
