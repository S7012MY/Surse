#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define DN 10005
using namespace std;

int n,m,sz,c,ind[DN],mmi,mma;
string cv[DN],mi,ma;

int lcp(string a, string b) {
	int i;
	for(i=0; i<a.size() && i<b.size(); ++i)
		if(a[i]!=b[i]) break;
	return i;
}

bool cmp(const int &a, const int &b) {
	return strcmp(cv[a].c_str(),cv[b].c_str())<0;
}

int main()
{
	ifstream f("ratina.in");
	ofstream g("ratina.out");
	f>>n>>m;
	ind[DN-1]=DN;
	for(int i=1; i<=n; ++i) f>>cv[i],ind[i]=i;
	sort(ind+1,ind+n+1,cmp);
	for(int i=1; i<=m; ++i) {
		f>>sz;
		mmi=DN-1;mma=0;
		for(int i=1; i<=sz; ++i) {
			f>>c;
			if(ind[c]>ind[mma]) mma=c;
			if(ind[c]<ind[mmi]) mmi=c;
		}
		g<<lcp(cv[mmi],cv[mma])<<'\n';
	}
	return 0;
}