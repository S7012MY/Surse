#include <fstream>
#include <string>
#include <vector>
#define DN 2005
using namespace std;

vector<int> el[DN];
int n,m,ind[DN];
string v[DN];

bool cmp(const int &a,const int &b) {
	return el[a]<el[b];
}

int main()
{
	ifstream f("binar.in");
	ofstream g("binar.out");
	f>>n>>m;
	f.get();
	for(int i=1; i<=n; ++i) getline(f,v[i]);
	for(int i=1; i<=n; ++i) for(int j=0; j<m; ++j) el[j].push_back(v[i][j]-'0'),ind[j]=j;
	sort(ind,ind+m,cmp);
	for(int i=0; i<m; ++i) g<<ind[i]+1<<' ';
	return 0;
}
