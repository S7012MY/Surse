#include <cstdio>
#include <cstring>
#define DN 4*100005

int n,c,gls,gld,p,va;
long long ai[DN];

void update(int vn,int ls,int ld) {
}

int main()
{
	int t,c,op,a,b,v;
	for(scanf("%d",&t);t;--t) {
		scanf("%d %d",&n,&c);
		memset(ai,0,sizeof(ai));
		for(int i=0; i<c; ++i) {
			scanf("%d %d %d",&op,&a,&b);
			if(op) {
			}else {
				scanf("%d",&v);
				va=v;
				for(int i=a; i<=b; ++i) {
					p=i;
					update(1,1,n);
				}
			}
		}
	}
	return 0;
}