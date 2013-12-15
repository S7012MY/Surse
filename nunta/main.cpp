#include <cstdio>
#include <cstring>

int x[1000],y[1000],z[1000];

void add (int a[],int b[]) {
	int i,t=0,nc=0,t2=0;
	for(i=999; i>999-a[0] || t; i--,++nc) {
		t=(a[i]+b[i]+t)/10;
		a[i]=(t2+a[i]+b[i])%10;
		t2=t;
	}
	a[0]=nc;
	//printf("%d\n",a[0]);
}


int main()
{
	int n,i=0,ok=0;
	freopen("nunta.in","r",stdin);
	freopen("nunta.out","w",stdout);
	scanf("%d",&n);
	x[999]=0;
	y[999]=1;
	x[0]=y[0]=1;
	while(i++<n+1) {
		memcpy(z,x,sizeof(x));
		add(x,y);
		memcpy(y,z,sizeof(z));
	}
	//printf("%d",x[0]);
	for(i=999-x[0]+1; i<=999; i++) printf("%d",x[i]);
	return 0;
}
