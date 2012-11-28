#include <fstream>
#include <cstdlib>
#include <ctime>
#define DN 10000
using namespace std;

int main()
{
	ofstream g("inversiuni.in");
	srand(time(NULL));
	int i=1;
	while(rand()&1 || i) {
		int n=rand()%DN+1;
	
		g<<n<<'\n';
		for(int i=0; i<n; ++i)
			g<<rand()%DN+1<<' ';
		if(i==1) --i;
	}
	return 0;
}
