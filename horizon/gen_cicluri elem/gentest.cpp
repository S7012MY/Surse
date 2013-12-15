#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	ofstream g("input.txt");
	int n=rand()%200+1;
	int nmax=(n*(n-1))/2;
	int m=rand()%nmax+1;
	g<<n<<' '<<m<<'\n';
	for(int i=1; i<=m; ++i) {
		int a,b;
		for(a=rand()%n+1,b=rand()%n+1;a==b;a=rand()%n+1,b=rand()%n+1);
		g<<a<<' '<<b<<'\n';
	}
}
