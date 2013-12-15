#include <fstream>
#include <vector>
using namespace std;

int n,nrp;
vector<int> v[300];

int main()
{
	ifstream f("lacate.in");
	ofstream g("lacate.out");
	f>>n;
	for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j) {
		++nrp;
		v[i].push_back(nrp);
		v[j].push_back(nrp);
	}
	g<<nrp<<' '<<n-1<<'\n';
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<v[i].size(); ++j) g<<v[i][j]<<' ';
		g<<'\n';
	}
	return 0;
}