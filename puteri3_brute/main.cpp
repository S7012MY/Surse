#include <iostream>
#include <fstream>
#define LL long long
#define int64 long long
#define MOD 1000000007
using namespace std;

int n,k,N,K;

inline int64 power (int64 N, int64 K) {
	if (! K) return 1;

	int64 halfpower = power (N, K / 2);

	if (K % 2) return (((halfpower * halfpower) % MOD)*1LL * N) % MOD;
	return (halfpower * halfpower) % MOD;
}

int main()
{
    ifstream f("puteri3.in");
    ofstream g("puteri3.out");
    f>>n>>k;
    N=n; K=k;
    LL rez=0;
    for(int i=1; i<=n; ++i) rez=(rez+power(i,k))%MOD;
    g<<rez;
    return 0;
}
