#include <cstdio>
#include <cstring>
#define DN 3005
#define NO 1000

int t,n,freq[DN];

int main()
{
	scanf("%d",&t);
	int nr,ok,r;
	for(;t;--t) {
		ok=0;
		memset(freq,0,sizeof(freq));
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) {
			scanf("%d",&nr);
			nr+=NO;
			int cmp=(n>>1);
			if(n&1) ++cmp;
			if(++freq[nr]>cmp) ok=1,r=nr-NO;
		}
		if(ok) printf("YES %d\n",r);
		else printf("NO\n");
	}
	return 0;
}


