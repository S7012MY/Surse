#include <cstdio>
#define REST 34949

long long putere(long long x,long long y) {
	long long rezultat=1,baza=x,exponent=y;
	while(exponent>0) {
		while(!(exponent%2)) {
			exponent>>=1;
			baza=(baza*baza)%REST;
		}
		exponent--;
		rezultat=(rezultat*baza)%REST;
	}
	return rezultat;
}

int main()
{
	long long n,p;
	FILE *f=fopen("gxor.in","r");
	FILE *g=fopen("gxor.out","w");
	fscanf(f,"%lld %lld",&n,&p);
	fprintf(g,"%lld",putere(2,n*n-p));
	fclose(f);
	fclose(g);
	return 0;
}

