#include<cstdio>
#include<bitset>
using namespace std;
bitset <1300015>a;
int main () {
	long long i,j,c=0,uv=0;
	int k;
	freopen("prim.in","r",stdin);
	freopen("prim.out","w",stdout);
	scanf("%d",&k);
	for(i=2;c!=k+1;++i){
		if(a[i]==0){
			++c;
			uv=i;
		for(j=i*i;j<=1300005;j=j+i){
				a[j]=1;
			}
		}
	}


	printf("%lld",uv*uv);
	return 0;
}
