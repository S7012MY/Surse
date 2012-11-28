#include<stdio.h>

	int fuel,m,k,time,i,d[1005],s[1005];
int main()
{
        freopen("oldpeykan.in","r",stdin);
    freopen("oldpeykan.out","w",stdout);
	scanf("%d %d",&m,&k);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&d[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&s[i]);
	}
	fuel=0;
	time=0;
	for(i=1;i<=m;i++)
	{

		fuel+=s[i];
		while(fuel<d[i])
		{
			fuel+=s[i];
			time+=k;
		}
		time+=d[i];
		fuel-=d[i];
	}
	printf("%d\n",time);
	return 0;
}
