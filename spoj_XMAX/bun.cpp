#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
int N,g[65][101];
ll gauss()
{
	ll ret=0;
	for(int i=0;i<61;i++)
	{
		int j=0;
		while(j<N&&g[i][j]==0)j++;
		if(j!=N)
		{
			ret|=1LL<<(60-i);
			for(int k=i+1;k<61;k++)
			if(g[k][j])
			for(int l=0;l<=N;l++)
			g[k][l]^=g[i][l];
		}
		else if(!g[i][N])ret|=1LL<<(60-i);
	}
	return ret;
}
int main()
{
  freopen("date.in","r",stdin);
  freopen("date.out","w",stdout);
	while(~scanf("%d",&N))
	{
		ll a;
		for(int i=0;i<N;i++)
		{
			scanf("%I64d",&a);
			for(int j=0;j<61;j++)
			g[60-j][i]=(a>>j)%2;
		}
		for(int i=0;i<61;i++)
		g[i][N]=1;
		printf("%I64d\n",gauss());
	}
}
