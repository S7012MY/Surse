#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream g("test.out");
	for(int i=1; i<=50;++i) {
		for(int j=1; j<=50; ++j) g<<"A";
		g<<",";
	}
	return 0;
}