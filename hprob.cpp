// hprobb.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef double mat22[24][24];
mat22 mi,mu,rezultat;


char perm[24][5]={"ABCD","ABDC","ACBD","ACDB","ADBC","ADCB",
				  "BACD","BADC","BCAD","BCDA","BDAC","BDCA",
				  "CABD","CADB","CBAD","CBDA","CDAB","CDBA",
				  "DABC","DACB","DBAC","DBCA","DCAB","DCBA"};

double vi[24],vr[24];

int op1 (int i) {
	char vector[5],c,*pc;
	strcpy(vector,perm[i]);
	c=vector[3];
	vector[3]=vector[2];
	vector[2]=vector[1];
	vector[1]=vector[0];
	vector[0]=c;
	pc=(char*) bsearch(vector,perm,24,5,(int(*)(const void*,const void*)) strcmp);
	return (pc-&perm[0][0])/5;//fiecare el are lungimea 5
}

int op2 (int i) {
	char vector[5],*pc;
	strcpy(vector,perm[i]);
	vector[0]=perm[i][3];
	vector[1]=perm[i][2];
	vector[2]=perm[i][1];
	vector[3]=perm[i][0];
	vector[4]=NULL;
	pc=(char*) bsearch(vector,perm,24,5,(int(*)(const void*,const void*)) strcmp);
	return (pc-&perm[0][0])/5;//fiecare el are lungimea 5
}

int op3 (int i) {
	char vector[5],c,*pc;
	strcpy(vector,perm[i]);
	vector[0]=perm[i][0];
	vector[1]=perm[i][2];
	vector[2]=perm[i][1];
	vector[3]=perm[i][3];
	vector[4]=NULL;
	pc=(char*) bsearch(vector,perm,24,5,(int(*)(const void*,const void*)) strcmp);
	return (pc-&perm[0][0])/5;//fiecare el are lungimea 5
}

void inmultire(mat22 a,mat22 b, mat22 c) {
	int i,j,k;
	for(i=0; i<24; i++) 
		for(j=0; j<24;j++) {
			c[i][j]=0;
			for(k=0; k<24; k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
}

void putere(long k, mat22 a) {
	long exponent=k;
	int lt=sizeof(mat22);
	mat22 baza,rez,rez2;
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
	for(int i=0; i<24; i++) {
		vr[i]=0;
		for(int j=0; j<24; j++)
			vr[i]+=rezultat[i][j]*vi[j];
	}
}

int main()
{
	int t,i,j;
	long n;
	double p1,p2,p3,p4;
	vi[0]=1;
	FILE*f=fopen("hprob.in","r");
	FILE *g=fopen("hprob.out","w");
	fscanf(f,"%d",&t);
	for(i=0; i<t; i++) {
		fscanf(f,"%ld %lf %lf %lf",&n,&p1,&p2,&p3);
		p4=1-p1-p2-p3;
		for(j=0; j<24;j++) {
			mi[j][j]=p4;
			mu[j][j]=1;
			//initializarea matricei de trecere
			mi[j][op1(j)]=p1;
			mi[j][op2(j)]=p2;
			mi[j][op3(j)]=p3;
		}
		memcpy(rezultat,mu,sizeof(mat22));
		putere(n,mi);
		inmultirev();
		fprintf(g,"%7.5lf\n",vr[0]);
	}
	fclose(f);
	fclose(g);
	return 0;
}

