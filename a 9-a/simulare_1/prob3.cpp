#include <fstream>
using namespace std;

int mat[10][10],n,rez;

int isp(int n) {
	if(n<2) return 0;
	for(int i=2; i*i<=n; ++i) if(0==n%i) return 0;
	return 1;
}

bool check(int a, int b, int x, int y) {
	for(int i=a; i<=x; ++i) for(int j=b; j<=y; ++j) if(!isp(mat[i][j])) return 0;
	return 1;
}

int main()
{
	ifstream f("matrice.in");
	ofstream g("matrice.out");
	f>>n;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) f>>mat[i][j];
	for(int i1=1; i1<=n; ++i1) for(int j1=1; j1<=n; ++j1)
		for(int i2=i1; i2<=n; ++i2) for(int j2=j1;j2<=n; ++j2) if(check(i1,j1,i2,j2) {
			int ll=i2-i1+1,lc=j2-j1+1;
			rez=max(rez,ll*lc);
		}
	g<<rez;
	return 0;
}