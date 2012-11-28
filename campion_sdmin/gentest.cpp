#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	//freopen("sdmin.in","r",stdin);
	freopen("sdmin.in","w",stdout);
	srand(time(NULL));
	int n=rand()%500+1;
	//int n=500;
	int k=rand()%100000+1;
	printf("%d\n%d\n",n,k);
	for(int i=1; i<=n; ++i) {
		int ld=rand()%100+1;
		int ls=rand()%ld;
		int y=rand()%k;
		//ls-=100000; ld-=100000;
		printf("%d %d %d\n",ls,ld,y);
	}
	return 0;
}
