#include <cstdio>
#define DN 705
#define N 100

int n,k,v[DN][DN],sp[DN][DN];

int main()
{
	freopen("radioactiv.in","r",stdin);
	freopen("radioactiv.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=N; i<n+k+N; ++i) for(int j=N; j<n+k+N;++j) {
		if(i<n+N && j<n+N) scanf("%d",&v[i][j]);
		sp[i][j]=sp[i][j-1]+sp[i-1][j]+v[i][j]-sp[i-1][j-1];
	}
	int vl=999999999,c=0;
	for(int i=N; i<n+N; ++i) for(int j=N;j<n+N; ++j) {
		int sum=v[i][j];
		for(int d=1; d<k; ++d) sum+=sp[i+d][j+d]-sp[i+d][j-d-1]-sp[i-d-1][j+d]+sp[i-d-1][j-d-1];
		if(sum<vl) vl=sum,c=1;
		else if(sum==vl) ++c;
	}
	printf("%d",c);
	return 0;
}
	
