#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> v;

int main() {
	ifstream f("intercresc.in");
	ofstream g("intercresc.out");
	f>>n>>m;
	for(int i=1; i<=n+m; ++i) {
		int x;
		f>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); ++i) g<<v[i]<<' ';
}
