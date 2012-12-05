#include <fstream>
using namespace std;

int n;

int main() {
	ifstream f("sah.in");
	ofstream g("sah.out");
	f>>n;
	for(int i=1; i<=n-2; ++i) {
		int lc=i;
		if(lc%2==0) --lc;
		for(int j=1; j<=n; ++j)
			if(j>(i+1)/2) g<<lc+1<<' ';
			else g<<lc<<' ';
		g<<'\n';
	}
	for(int i=1; i<3; ++i) {
		for(int j=1; j<=n; ++j) g<<n-1<<' ';
		g<<'\n';
	}
	return 0;
}