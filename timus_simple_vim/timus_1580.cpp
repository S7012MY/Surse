#include <iostream>
#include <vector>
#include <bitset>
#include <cstdlib>
#define DN 1005
#define MLT 1000000
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

bitset<DN> viz;
int n,m,ct[DN],amsol;
double vf[DN];
vector<per> gr[DN];

void impos() {
	cout<<"IMPOSSIBLE";
	exit(0);
}

void dfs(int s, int vl,int f,int par) {
	viz[s]=1;
	ct[s]=vl;

	for(it i=gr[s].begin();i!=gr[s].end(); ++i)
		if(0==viz[i->x]) dfs(i->x,vl-par*i->y,s,-par);
		else if(i->x!=f) {
			amsol=1;
			vf[i->x]=ct[i->x]/(-2.0);
		}
}

void comp(int s,int vl) {
	vf[s]=vl;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
		if(vf[i->x]!=-MLT) {
			if(vf[i->x]!=vl-i->y) impos();
			continue;
		}
		comp(i->x,vl-i->y);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0; i<n; ++i) vf[i]=-MLT;
	for(int i=0; i<m; ++i) {
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		gr[a].push_back(mp(b,c));
		gr[b].push_back(mp(a,c));
	}
	for(int i=0; i<n; ++i) if(0==viz[i]) {
		amsol=0;
		dfs(i,0,-1,1);
		if(!amsol) impos();
		cout<<vf[1]<<' ';
		comp(i,vf[i]);
	}
	for(int i=0; i<n; ++i) cout<<vf[i]<<'\n';
	return 0;
}
