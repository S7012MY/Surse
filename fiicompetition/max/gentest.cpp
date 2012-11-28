#include <fstream>
#include <cstdlib>
#include <ctime>
#define DN 21
#define DV 1000000
using namespace std;

int main()
{
	srand(time(NULL));
	ofstream g("max.in");
	//int n=rand()%DN+1;
	g<<DV<<'\n';
	for(int i=1; i<=DV; ++i)
		if(i&1) g<<DV<<' ';
		else g<<1<<' ';
	//g<<rand()%DV+1<<' ';
	return 0;
}
