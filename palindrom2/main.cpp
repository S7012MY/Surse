#include <cstdio>
#include <string.h>

char a[2002];
int n;

int pali(int k) {
	int i = k;
	int j = n;
	int ok =1 ;
	while ( i < j && ok ) {
	if( a[i] != a[j])
		ok =0;
	i++;
	j--;
	}
	return ok;
}


int main()
{
	int i=0,j;
	FILE *f=fopen("palindrom2.in","r");
	FILE *g=fopen("palindrom2.out","w");
	fgets(a,1000,f);
	n=strlen(a);
	n--;
	while (!pali(i++));
	a[n+i]=NULL;
	i-=2;
	j=n+1;
	while(i>=0)
		a[j++]=a[i--];
	fprintf(g,"%s",a);
	fclose(f);
	fclose(g);
	return 0;
}
