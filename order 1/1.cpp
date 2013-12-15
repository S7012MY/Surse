#include <fstream>
using namespace std;

int n,x,sm;

int main(){ 
	ifstream f("conserve.in");
	ofstream g("conserve.out");
	f>>x>>n;
	for(int i=1; i<=n; ++i) {
		f>>x;
		sm+=x;
	}
	if(sm>=1000000) while(1);
	return 0;
}