#include <cstdio>
#include <cstring>
#include <cmath>
#define DIM 41
#define REST 666777
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
	FILE *f=fopen("nkbiti.in","r");
	FILE *g=fopen("nkbiti.out","w");
	fscanf(f,"%lld %lld ",&n,&capa);
	if (capa>n) {
		fprintf(g,"0\n");
		goto sfarsit;
	}
	else if(capa==n) {
		pd=pow((double) 2,(double)capa);
		fprintf(g,"%lld",pd%REST);
		goto sfarsit;
	}
	pd=pow((double) 2,(double)capa);
	printf("%lld",pd);
	//initializare vector
	capa++;
	for(i=0; i<capa; i++) {
		v[i]=pd;
		pd>>=1;
	}
	matun();
	//initializare matrice initiala
	for(i=0; i<capa; i++) mi[0][i]=1;
	for(i=1; i<capa; i++) mi[i][i-1]=1;
	//////
	if(capa==2) putere(n-1,mi);
	else putere(n-(capa-1),mi);
	inmultirev();
	fprintf(g,"%lld",vr[0]);
sfarsit:fclose(f);
	fclose(g);
	return 0;
}


