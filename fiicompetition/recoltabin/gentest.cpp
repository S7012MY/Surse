#include <fstream>
#include <cstdlib>
#include <ctime>
#define DN 11
#define DG 1000
#define DK 105
using namespace std;

int n,k,s,v[DN+5],st;

int main() {
	srand(time(NULL));
	ofstream g("recoltabin.in");
	n=rand()%DN+1;
	k=rand()%DK+1;
	for(int i=1; i<=n; ++i) {
		v[i]=rand()%DG+1;
		st+=v[i];
	}
	s=rand()%st+1;
	g<<n<<' '<<k<<' '<<s<<'\n';
	for(int i=1; i<=n; ++i) g<<v[i]<<' ';
	return 0;
}
