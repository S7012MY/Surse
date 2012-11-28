#include <fstream>
#include <vector>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

int n,m,sz,fst[DN],lst[DN];
vector<int> gr[DN];

void dfs(int s, int f) {
	fst[s]=++sz;
	lst[s]=sz;
	for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(*i!=f) {
		dfs(*i,s);
		lst[s]=++sz;
	}
}

int main() {
	ifstream f("maimute.in");
	ofstream g("maimute.out");
	f>>n;
	for(int i=1; i<n; ++i) {
		int a,b;
		f>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1,0);
	f>>m;
	for(int i=1; i<=m; ++i) {
		int a,b;
		f>>a>>b;
		if((fst[a]<fst[b] && lst[a]>lst[b]) ||(fst[a]>fst[b] && lst[a]<lst[b])) g<<"DA\n";
		else g<<"NU\n";
	}
}