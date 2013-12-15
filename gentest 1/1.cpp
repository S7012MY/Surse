#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	srand(time(NULL));
	for(int i=0; i<10; ++i) {
		char fi[100],fo[100];
		sprintf(fi,"%d-simpla.in",i);
		sprintf(fo,"%d-simpla.ok",i);
		int n=rand()%1000+1,s[1005],nru,unice[1005];
		ofstream f(fi);
		ofstream g(fo);
		nru=rand()%n+1;
		f<<n<<'\n';
		for(int i=0; i<nru; ++i) unice[i]=rand()%100000;
		for(int i=1; i<=n; ++i) {
			s[i]=unice[rand()%nru];
			f<<s[i]<<' ';
		}
		sort(s+1,s+n+1);
		g<<s[1]<<' ';
		for(int i=2; i<=n; ++i) if(s[i]!=s[i-1]) g<<s[i]<<' ';
	}
	return 0;
}