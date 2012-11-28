//Complexitate : MAX * MAX

#include <stdio.h>


using namespace std;

#define MAX 5005

short A[MAX][MAX];
int MAXX, MAXY;
int x, y, i, j;
int N, Rez, K;

int main()
{
	freopen("puncte.in","r",stdin);
	freopen("puncte.out","w",stdout);
	
	scanf("%d %d",&N,&K);
	for (i=1; i<=N; ++i){
		scanf("%d %d",&x,&y);
		++A[x][y];
		MAXX = MAXX < x ? x : MAXX;
		MAXY = MAXY < y ? y : MAXY;
	}
	
	MAXX = MAXY = Rez = MAXX > MAXY ? MAXX : MAXY;
	for (i=1; i<=MAXX; ++i)
		for (j=1; j<=MAXY; ++j)
			A[i][j] = A[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
	
	for (i=MAXX; i>=Rez-1; --i)
		for (j=MAXY; j>=Rez-1; --j)
			while (Rez > 0 && (A[i][j] - A[i][j-Rez+1] - A[i-Rez+1][j] + A[i-Rez+1][j-Rez+1]) >= K)
				--Rez;
			
	printf("%d\n", Rez-1);
	
	return 0;
}