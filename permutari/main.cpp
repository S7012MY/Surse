#include <cstdio>

long s[11],n;

FILE *f,*g;

static void permlex(long k) {
	long i,j;
	int ok;
	if (k==n) {
        for (i=1;i<=n; i++)
			fprintf(g,"%ld ",s[i]);
        fprintf(g,"\n");
	}
	else {
		for (i=1; i<=n; i++) {
			ok=1;
			for (j=1; j<=k;j++)
				if (s[j]==i) {
					ok=0;
					break;
				}
			if (ok) {
				s[k+1]=i;
				permlex(k+1);
			}
		}
	}
}

int main()
{
	f=fopen("permutari.in","r");
	g=fopen("permutari.out","w");
	fscanf(f,"%ld",&n);
	permlex(0);
	fclose(f);
	fclose(g);
	return 0;
}

