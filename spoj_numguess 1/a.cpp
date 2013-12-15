#include <cstdio>

int main()
{
	int i, step,a,b,ls,ld;
	char c[10];
	scanf("%d %d",&a,&b);
	ld=b-a;
	ls=0;
	for (step=1; step<=ld; step<<=1);
    for (i=0; step; step >>= 1)
        if (i+step<=ld) {
			printf("%d\n",i+step+a);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='L') i += step;
			else if(c[0]=='W') return 0;
		}

	return 0;
}