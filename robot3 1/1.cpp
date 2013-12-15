#include <iostream>
#include <fstream>
#include <bitset>
#include <map>
#define DM 5005
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;

int n,m,l,c,vc,sz,x,i;
per pth[DM];
bitset<DN> vi[DN];
map<per,int> mp;

int main()
{
	ifstream f("robot3.in");
	ofstream g("robot3.out");
	f>>n>>m>>l>>c;
	pth[++sz]=make_pair(l,c);
	vi[l][c]=1;
	char cc;
	for(i=1; i<=m; ++i) {
		f>>cc;
		if('N'==cc) --l;
		else if('S'==cc) ++l;
		else if('E'==cc) ++c;
		else --c;
		pth[++sz]=make_pair(l,c);
		vi[l][c]=1;
	}
	++m;
	for(i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
		f>>vc;
		if(vi[i][j]) mp[make_pair(i,j)]=vc;
	}
	vc=0;
	for(i=1;i<=m;--vc,++i) {
		vc+=mp[pth[i]];
		if(0==vc) break;
	}
	if(i>m) --i;
	g<<pth[i].x<<' '<<pth[i].y;
	return 0;
}