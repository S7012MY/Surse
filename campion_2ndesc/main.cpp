#include <cstdio>
#include <cstring>
#include <cmath>
#define DIM 4
#define REST 666013
typedef long long mat22[DIM][DIM];
long long v[DIM],vr[DIM],capa;
mat22 mi,mu,rezultat;

void scriere(mat22 a) {
	for(int i=0; i<capa; i++) {
		for(int j=0; j<capa; j++)
			printf("%lld ",a[i][j]);
		printf("\n");
	}
}

void inmultire(mat22 a,mat22 b, mat22 c) {
	int i,j,k;
	for(i=0; i<capa; i++)
		for(j=0; j<capa;j++) {
			c[i][j]=0;
			for(k=0; k<capa; k++)
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%REST)%REST;
		}
}

void putere(long long k, mat22 a) {
	long long exponent=k;
	int lt=sizeof(mat22);
	mat22 baza,rez,rez2;
	memcpy(rezultat,mu,lt);
	//printf("%d\n",lt);
	memcpy(baza,a,lt);
	while(exponent>0) {
		while(!(exponent%2)) {
			inmultire(baza,baza,rez);
			//scriere(rez);
			memcpy(baza,rez,lt);
			exponent>>=1;
		}
		exponent--;
		inmultire(rezultat,baza,rez2);
		memcpy(rezultat,rez2,lt);
	}
	//scriere(rezultat);
}

void inmultirev() {
	for(int i=0; i<capa; i++) {
		vr[i]=0;
		for(int j=0; j<capa; j++)
			vr[i]=(vr[i]+(rezultat[i][j]*v[j])%REST)%REST;
	}
}

void matun() {
	for(int i=0; i<capa; i++)
		mu[i][i]=1;
}

int main()
{
	long long n,i,pd;
	FILE *f=fopen("2ndesc.in","r");
	FILE *g=fopen("2ndesc.out","w");
	fscanf(f,"%lld %lld ",&n);
	capa=3;
	v[0]=1; v[1]=2; v[2]=4;
	if (capa>=n) {
		fprintf(g,"%d",v[n-1]);
		return 0;
	}
	//initializare vector
	matun();
	//initializare matrice initiala
	mi[0][1]=mi[1][2]=mi[2][0]=mi[2][1]=mi[2][2]=1;
	//////
	putere(n-(capa-1),mi);
	inmultirev();
	fprintf(g,"%lld",vr[1]);
    fclose(f);
	fclose(g);
	return 0;
}

