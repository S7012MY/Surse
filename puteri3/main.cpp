#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxK 110
#define MOD 1000000007LL
#define LL unsigned long long
using namespace std;

LL S[maxK];
LL cmb[maxK][maxK];


inline LL power(LL N, LL K) {
	if(! K) return 1;

	LL halfpower=power(N, K / 2LL);

	if(K % 2LL) return(((halfpower * halfpower) % MOD) * N) % MOD;
	return(halfpower * halfpower) % MOD;
}


int main()
{
	freopen("puteri3.in", "r", stdin);
	freopen("puteri3.out", "w", stdout);
	long long N, K;
	scanf("%lld %lld", &N, &K);
	if(N<1000000) {
	    LL rez=0;
        for(int i=1; i<=N; ++i) rez=(rez+power(i,K))%MOD;
        printf("%d",rez);
        return 0;
	}
	cmb[1][1]=1;
	for(int i=1; i <= K + 1; ++ i) cmb[i][0]=1;
	for(int i=2; i <= K + 1; ++ i)
		for(int j=1; j <= i; ++ j) {
		    cmb[i][j]=cmb[i - 1][j] + cmb[i - 1][j - 1];
		    if(cmb[i][j]>=MOD) cmb[i][j]-=MOD;
		}

	S[1]=(( N  *(LL)(N + 1LL ) % MOD) * power(2,MOD-2))%MOD;
	S[2]=((S[1] *(((2LL * N) % MOD) + 1LL)) * power(3,MOD-2))%MOD;
	//S[3]=((( N  *(LL)(N + 1LL ) % MOD)*( N  *(LL)(N + 1LL ) % MOD))*power(4,MOD-2)) % MOD;

	for(int i=3; i <= K; ++ i) {
		LL cur=power(N + 1, i + 1);

		cur -= N;
		cur --;
		for(;cur<0;) cur+=MOD;

		for(int kk=i - 1, nn=2; kk >= 1 && nn <= i; -- kk, ++ nn) {
			cur -=((cmb[i + 1][nn] * S[kk]) % MOD);
			for(;cur < 0;) cur+=MOD;
		}
		//cur+=MOD;

		//cout << cur << " " ;
		cur *= power(i + 1, MOD - 2);
		//cur /= i + 1;

		S[i]=cur;
		S[i] %= MOD;
	}
	printf("%lld", S[K]);
	return 0;
}
