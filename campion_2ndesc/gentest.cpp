#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int n=rand()%100004+1;
	ofstream g("2ndesc.in");
	g<<n;
	return 0;
}
