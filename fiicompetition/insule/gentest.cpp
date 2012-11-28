#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	ofstream g("insule.in");
	g<<"500 500\n";
	for(int i=0; i<500; ++i) {
		for(int j=0; j<500; ++j)
			if(j==250 && i!=250) g<<1;
			else g<<0;
		g<<'\n';
	}
	return 0;
}
