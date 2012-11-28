#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define DN 305
#define EPS 1e-8
using namespace std;

ifstream f("gauss.in");
ofstream g("gauss.out");
int n,m;
double a[DN][DN],b[DN];

void bagaZero() {
	int i,j,k,l,u;
	for(i=j=1;i<=n && j<=m;) {
		for(k=i; k<=n; ++k) if(fabs(a[k][j])>EPS) break;
		if(k>n) {++j; continue;}
		if(k!=i) for(l=1; l<=m+1; ++l) swap(a[i][l],a[k][l]);
		for(l=m+1; j<l; --l) a[i][l]/=a[i][j];
		for(u=i+1; u<=n; ++u) {
			for(l=j+1; l<=m+1; ++l) a[u][l]-=a[u][j]*a[i][l];
			a[u][j]=0;
		}
		++i; ++j;
	}
}

void rezSsTr() {
	int i,j,k;
	for(int i=n; 0<i; --i) for(j=1; j<=m+1; ++j) if(fabs(a[i][j])>EPS) {
		if(j==m+1) {
			g<<"Imposibil";
			exit(0);
		}
		b[j]=a[i][m+1];
		for(k=j+1; k<=m; ++k) b[j]-=b[k]*a[i][k];
		break;
	}
}

int main()
{
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m+1; ++j) f>>a[i][j];
	bagaZero();
	rezSsTr();
	for(int i=1; i<=m; ++i) g<<fixed<<setprecision(8)<<b[i]<<' ';
	return 0;
}