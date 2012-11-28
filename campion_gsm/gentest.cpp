#include <cstdio>
#include <cstdlib>
#include <ctime>

int n,dxj,dyj,dxs,dys;

int rand(int a,int b) {
	return rand()%(b-a)+a;
}

int main() {
	freopen("gsm.in","w",stdout);
	dxs=rand()%1000+1;
	dys=rand()%1000+1;
	dxj=rand()%dxs;
	dyj=rand()%dys;
	n=rand()%200+1;
	printf("%d\n",n);
	for(int i=1; i<=n; ++i) printf("%d %d\n",rand(dxj,dxs),rand(dyj,dys));
	printf("%d %d %d %d",dxj,dyj,dxs,dys);
	return 0;
}
