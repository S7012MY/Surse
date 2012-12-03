#include <fstream>
#include <vector>
#include <bitset>
#define DN 2505
using namespace std;

typedef vector<int>::iterator it;

int n,m,l[55],r[55];
char mt;
vector<int> gr[DN];
bitset<DN> viz;

int cupl(int s) {
	if(viz[s]) return 0;
	viz[s]=1;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(r[*i]==0 || cupl(r[*i])) {
		l[s]=*i; r[*i]=s;
		return 1;
	}
	return 0;
}

int main() {
	ifstream f("s013.in");
	ofstream g("s013.out");
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		f>>mt;
		if(mt=='*') gr[i].push_back(j);
	}
	for(int ok=1;ok;) {
		ok=0; viz&=0;
		for(int i=1; i<=n; ++i) ok|=cupl(i);
	}
	int r=0;
	for(int i=1; i<=n; ++i) r+=(l[i]>0);
	g<<r;
	return 0;
}