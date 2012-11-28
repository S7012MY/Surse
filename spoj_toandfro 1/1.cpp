#include <cstdio>
#include <cstring>
#include <bitset>
#define DN 205
using namespace std;

bitset<DN> viz;

int main()
{
	int x=1,sz;
	char di[DN];
	for(;;) {
		scanf("%d",&x);
		if(0==x) break;
		scanf("%s",di);
		viz&=0;
		sz=strlen(di);
		x=sz/x;
		for(int i=0;i<sz-1; ++i) {
			for(;viz[i];++i);
			for(int j=i; j<sz-1; j+=x+2) printf("%c",di[j]),viz[j]=1;
		}
		printf("\n");
	}
	return 0;
}
