#include<stdio.h>

FILE *f = fopen("narbi.in","r");
FILE *g = fopen("narbi.out","w");

#define ll long long

static unsigned char wordbits[65536];
int N,K,X1,X2;
ll Z = 0;

void citire(void)
{
	fscanf(f,"%d %d %d",&N,&K,&X2);
}

inline int NrZerouri(ll a)
{
	int nr = 0;
	
	for(;a;nr += a%2,a /= 2);
	
	return nr;
}

inline int popcount( unsigned int i )
{
    return( wordbits[i&0xFFFF] + wordbits[i>>16] );
}

void CreareWord(void)
{
	for(int i=0;i<=65536;i++)
		wordbits[i] = NrZerouri(i);
}

void Rezolvare(void)
{	
	CreareWord();
	
	for(int i=1;i<=N;i++)
	{
		for(unsigned int i=X1+1;i<=X2;i++)
			Z += popcount(i);
		X1 = X2;
		X2 += Z%16 + 1;
		
		if(N-i+1 <= K)
			fprintf(g,"%d\n",Z);
	}
	
	//fprintf(g,"%I64d ",Z);
}

int main()
{
	citire();
	Rezolvare();
}