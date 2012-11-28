#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

FILE *g = fopen("lexic.in","w");

int main()
{
	fprintf(g,"10000 1000\n3\n");
	srand(time(NULL));
	for(int i=1;i<=10000;i++)
	{
		fprintf(g,"abc");
		for(int j=1;j<=1000-6;j++)
			fprintf(g,"%c",rand()%26+'a');
		fprintf(g,"cba\n");
	}
}
