#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("xerox.in");
	ofstream g("xerox.out");
	int t,n,rez,x,z;
	for(f>>t;t--;) {
		f>>n>>x>>x;rez=0;
		for(int i=1; i<=n; ++i) {
			f>>x; rez^=x;
			for(;x--;) f>>z>>z;
		}
		g<<(rez>0)<<'\n';
	}
	return 0;
}