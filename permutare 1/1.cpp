#include <fstream>
#include <algorithm>
#define DN 200005
using namespace std;

int n,v[DN],x;

int main()
{
	ifstream f("permutare.in");
	ofstream g("permutare.out");
	f>>n;
	int M=2*n+1,m=1;
	v[1]=n+1;
	for(int i=2; i<=(n<<1)+1; i+=2) {
		v[i]=m; v[i+1]=M;
		--M; ++m;
	}
	f>>x;
	for(int i=1; i<=n; ++i) {
		f>>x;
		if(0==x) continue;
		else if(1==x) swap(v[(i<<1)],v[(i<<1)+2]);
		else swap(v[(i<<1)+1],v[(i<<1)+3]);
	}
	for(int i=1; i<=(n<<1)+1; ++i) g<<v[i]<<' ';
	return 0;
}
