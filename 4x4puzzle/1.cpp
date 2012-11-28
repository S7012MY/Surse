#include <fstream>
using namespace std;

int main() {
	ifstream f("4x4puzzle.in");
	ofstream g("4x4puzzle.out");
	int t,pzero,nrm,v[16];
	for(f>>t;t--;) {
		nrm=0;
		for(int i=0; i<16; ++i) {
			f>>v[i];
			if(0==v[i]) pzero=(i>>2)+1;
		}
		for(int i=0; i<15; ++i) for(int j=i+1; j<16; ++j) if(v[j] && v[j]<v[i]) ++nrm;
		if((nrm&1)==(pzero&1)) g<<"DA\n";
		else g<<"NU\n";
	}
}
