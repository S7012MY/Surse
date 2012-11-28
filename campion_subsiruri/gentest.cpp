#include <fstream>
#include <ctime>
#include <cstdlib>
#define DN 1000
using namespace std;

int n,m,a,b;

int main()
{
	ofstream g("subsiruri.in");
	srand(time(NULL));
	n=rand()%DN+1;
	m=rand()%DN+2;
	b=rand()%DN+1;
	a=rand()%b;
	g<<n<<' '<<m<<' '<<a<<' '<<b<<'\n';
	for(int i=1; i<=n; ++i) g<<rand()%DN+1<<' ';
	return 0;
}
