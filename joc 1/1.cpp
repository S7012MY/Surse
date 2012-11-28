#include <fstream>
#define DN 2005
#define MULT -200000
using namespace std;

int a[DN][DN],bst[DN][DN],n,m,rez=MULT,pi,pj;

int main()
{
	ifstream f("joc.in");
	ofstream g("joc.out");
	for(int i=0; i<DN; ++i) for(int j=0; j<DN; ++j) bst[i][j]=MULT;
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>a[i][j];
	bst[1][1]=a[1][1];
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		if(1==j && 1==i) continue;
		a[i][j]-=max(bst[i-1][j],bst[i][j-1]);
		bst[i][j]=max(a[i][j],max(bst[i-1][j],bst[i][j-1]));
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(rez<a[i][j]) rez=a[i][j],pi=i,pj=j;
	g<<rez<<' '<<pi<<' '<<pj;
	return 0;
}
