#include <fstream>
#include <algorithm>
using namespace std;

typedef pair<int,int>per;

int n;
per v[100005];

long long rez,sc;

bool cmp(const per &a,const per &b) {
	return (double)a.second/a.first>(double)b.second/b.first;
}

int main()
{
	ifstream f("jsched.in");
	ofstream g("jsched.out");
	f>>n;
	for(int i=1; i<=n; ++i) f>>v[i].first>>v[i].second;
	sort(v+1,v+n+1,cmp);
	for(int i=1; i<=n; ++i) {
		sc+=v[i].first;
		rez+=sc*v[i].second;
	}
	g<<rez;
	return 0;
}