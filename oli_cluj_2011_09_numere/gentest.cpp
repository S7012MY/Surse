#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	//freopen("sdmin.in","r",stdin);
	freopen("numere.in","w",stdout);
	srand(time(NULL));
	int n=rand()%100+1;
	printf("%d",n);
	return 0;
}
