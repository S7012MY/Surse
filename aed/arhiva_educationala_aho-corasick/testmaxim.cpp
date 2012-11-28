#include <fstream>
using namespace std;

int main()
{
	ofstream g("ahocorasick.in");
	for(int i=1; i<=1000000; ++i) g<<"a";
	g<<'\n'<<100<<'\n';
	for(int i=1; i<=100; ++i) {
		for(int j=1; j<=10000; ++j) g<<"a";
		g<<'\n';
		//g<<"aa\n";
	}
	return 0;
}


