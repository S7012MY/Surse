#include <stdio.h>
#define DIM 5010
short A[DIM][DIM];
int N, m, K, X, Y, i, j, Maxx, Maxy, p, u;

int amk (int m) {
	int i, j, Max;
	Max = (Maxx > Maxy ? Maxx : Maxy);
	for (i=m;i<=Max;i++)
		for (j=m;j<=Max;j++)
			if (A[i][j] - A[i-m][j] - A[i][j-m] + A[i-m][j-m] >= K)
				return 1;
	return 0;
}


int main() {
	FILE *f = fopen("puncte.in","r");
	FILE *g = fopen("puncte.out","w");
	fscanf(f,"%d %d",&N,&K);
	for (i=1;i<=N;i++) {
		fscanf(f,"%d %d",&X, &Y);
		A[X][Y] ++;
		if (X > Maxx)
			Maxx = X;
		if (Y > Maxy)
			Maxy = Y;
	}
	fclose(f);
	for (i=1;i<=Maxx;i++)
		for (j = 1;j<=Maxy;j++)
			A[i][j] += (A[i-1][j] + A[i][j-1] - A[i-1][j-1]);
	
	p = 0; u = (Maxx > Maxy ? Maxx : Maxy);
	
	while (p<=u) {
		m = (p + u)/2;
		if (amk(m))
			u = m-1;
		else
			p = m+1;
	}
	fprintf(g,"%d\n",p-1);
	fclose(g);
	return 0;
}
