#include <fstream>
using namespace std;

int n;

int main() {
	ifstream f("sah.in");
	ofstream g("sah.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j)
			if(j>(i+1)/2) g<<2*i<<' ';
			else g<<2*i-1<<' ';
		g<<'\n';
	}
	return 0;
}