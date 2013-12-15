#include <fstream>
#include <cstdio>
using namespace std;

char in[55],out[55];

int main() {
	for(int i=0; i<20; ++i) {
		sprintf(in,"%d-puncte.in",i);
		sprintf(out,"grader_test%d.in",i+1);
		ifstream f(in);
		ofstream g(out);
		int n,a,b;
		f>>n; g<<n<<'\n';
		for(int i=1; i<=n; ++i) {
			f>>a>>b;
			g<<a<<' '<<b<<'\n';
		}
		f.close();
		g.close();
		sprintf(in,"%d-puncte.ok",i);
		sprintf(out,"grader_test%d.ok",i+1);
		f.open(in); g.open(out);
		f>>n; g<<n;
	}
		return 0;
}
