#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int n,m;


int main() 
{
	srand(time(NULL));
	ofstream g("jmenoasa.in");
	n=5; m=5;
	g<<n<<' '<<m<<'\n';
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) g<<rand()%100<<' ';
		g<<'\n';
	}
	return 0;
}
