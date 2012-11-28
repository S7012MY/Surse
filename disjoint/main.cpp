#include <cstdio>
#define DM 100001

int n,m,rang[DM],vect[DM];

int cautare(int el) {
	int i,j;
	for(i=el;i!=vect[i]; i=vect[i]);//cautam un nod care e indreptat spre el
	while(el!=vect[el]) {
		j=vect[el];
		vect[el]=i;
		el=j;
	}
	return i;
}

void reuniune(int x,int y) {
	if(rang[x]>rang[y])//daca multimea in care e x are rang mai mare
		vect[y]=x;//unesc nodul y cu x
	else vect[x]=y; //altfel unesc pe x cu y
	if(rang[x]==rang[y])//daca rangurile sunt egale creste rangul
		++rang[y];
}

int main()
{
	int i,tip,x,y;
	freopen("disjoint.in","r",stdin);
	freopen("disjoint.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1; i<=n; i++) {
		rang[i]=1;//fiecare multime are initial rangul 1
		vect[i]=i;
	}
	for(i=1; i<=m; i++) {
		scanf("%d %d %d",&tip,&x,&y);
		if(tip==1) reuniune(cautare(x),cautare(y));
		else
			if(cautare(x)==cautare(y)) printf("DA\n");
			else printf("NU\n");
	}
	return 0;
}
