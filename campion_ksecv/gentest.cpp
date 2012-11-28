#include <fstream>
#include <cstdlib>
#include <ctime>
#define DN 100000
#define DE 1000000000
#define DV 2000000001
using namespace std;

int main()
{
	ofstream g("ksecv.in");
	srand(time(NULL));
	//int n=rand()%DN+1;
	int n=DN;
	int k=rand()%100+1;
	g<<n<<' '<<k<<'\n';
	for(int i=1; i<=n; ++i) {
		g<<rand()%DV-DE<<' ';
	}
	return 0;
}
	
