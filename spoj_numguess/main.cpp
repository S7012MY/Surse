#include <cstdio>

int main()
{
	int m,ls,ld;
	char c[10];
	scanf("%d %d",&ls,&ld);
	for(;;) {
	    m=(ls+ld)>>1;
	    printf("%d\n",m);
	    fflush(stdout);
        scanf("%s",c);
        fflush(stdin);
        if(c[0]=='L') ls=m+1;
        else if(c[0]=='W') return 0;
        else ld=m-1;
	}
	return 0;
}

