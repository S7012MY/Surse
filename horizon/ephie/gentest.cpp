#include <ctime>
#include <cstdlib>
#include <fstream>
#define DN 10
#define VMAX 10001
using namespace std;

int n=5;

int main() 
{
	ofstream g("ephie.in");
	srand(time(NULL));
	//n=rand()%DN+1;
	g<<n<<' '<<rand()%n+1<<'\n';
	for(int i=1; i<=n; ++i) g<<rand()%VMAX<<' '<<rand()%VMAX<<'\n';
	return 0;
}
