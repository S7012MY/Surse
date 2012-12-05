#include <fstream>
using namespace std;

int n,m;

int main() {
	ifstream f("sah.in");
	f>>n;
	m=n-1;
	ofstream g("sah.out");
	for(int i=1; i<m; i+=2) {
		int lc=i,p=(i+1)/2;
		for(int j=1; j<=p; ++j) g<<lc<<' ';
		++lc;
		for(int j=p+1; j<=n; ++j) g<<lc<<' ';
		g<<'\n';
		--lc;
		for(int j=1; j<=p; ++j) g<<lc<<' ';
		++lc;
		for(int j=p+1; j<=n; ++j) g<<lc<<' ';
		g<<'\n';
	}
	for(int i=1; i<3; ++i) {
		for(int j=1; j<=n; ++j) g<<m<<' ';
		g<<'\n';
	}
	return 0;
}