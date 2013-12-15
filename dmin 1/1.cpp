//log(a*b)=log(a)+log(b) =))
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <cmath>
#define DN 1505
#define x first
#define y second
#define EPS 1e-9
#define MULT 2000000000
#define MOD 104659
#include <set>
using namespace std;

typedef pair<int, double> per;
typedef vector<per>::iterator it;

int n,m,rez[DN];
double d[DN];
bitset<DN> viz;
vector<per> gr[DN];
set<pair<double, int> > s;

void dij() {
	for(int i=1; i<=n; ++i) d[i]=MULT;
	rez[1]=1;
	for(s.insert(make_pair(0,1));s.size();s.erase(s.begin())) {
		double cst=s.begin()->x; int nod=s.begin()->y;
		for(it i=gr[nod].begin(); i!=gr[nod].end(); ++i) {
			if(fabs(d[i->x]-cst-i->y)<EPS) rez[i->x]=(rez[i->x]+rez[nod])%MOD;
			else if(cst+i->y<d[i->x]) {
				d[i->x]=cst+i->y;
				rez[i->x]=rez[nod];
				s.insert(make_pair(d[i->x],i->x));
			}
		}
	}
}

int main()
{
	ifstream f("dmin.in");
	ofstream g("dmin.out");
	f>>n>>m;
	for(int i=1; i<=m; ++i) {
		int a,b,c;
		f>>a>>b>>c;
		double lg=log((double)c);
		gr[a].push_back(make_pair(b,lg));
		gr[b].push_back(make_pair(a,lg));
	}
	dij();
	for(int i=2; i<=n; ++i) g<<rez[i]<<' ';
	return 0;
}
