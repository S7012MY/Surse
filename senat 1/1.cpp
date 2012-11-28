#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#define DN 505
using namespace std;

typedef vector<int>::iterator it;

bitset<DN> viz;
vector<int> gr[DN];
int n,m,l[DN],r[DN];

int cupl(int s) {
	if(viz[s]) return 0;
	viz[s]=1;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==r[*i] || cupl(r[*i])) {
		l[s]=*i; r[*i]=s;
		return 1;
	}
	return 0;
}

int main()
{
	ifstream f("senat.in");
	ofstream g("senat.out");
	f>>n>>m;
	f.get();
	string lc;
	for(int i=1; i<=m; ++i) {
		getline(f,lc);
		for(int j=0; j<lc.size(); ++j) {
			if(isdigit(lc[j])) {
				int nc=0;
				for(;isdigit(lc[j]);nc=nc*10+lc[j]-'0',++j);
				--j;
				gr[i].push_back(nc+n);
			}
		}
	}
	
	for(bool ok=1; ok;) {
		ok=0; viz&=0;
		for(int i=1; i<=m; ++i) if(0==l[i]) ok|=cupl(i);
	}
	for(int i=1; i<=m; ++i) if(0==l[i]) {
		g<<"0";
		return 0;
	}
	for(int i=1; i<=m; ++i) g<<l[i]-n<<'\n';
	return 0;
}