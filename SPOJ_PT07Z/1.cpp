#include <iostream>
#include <vector>
#include <bitset>
#include <list>
#define DN 10005
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
vector<int> gr[DN];
bitset<DN> viz;
list<per> g1;
int n,cn,grad[DN],sz,s1,s2,te,d[DN];

void dfs(int s, int ds) {
	viz[s]=1;
	d[s]=ds;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]) dfs(*i,ds+1);
}

int main()
{
	cin>>n;
	cn=n;
	for(int i=1; i<n; ++i) {
		int a,b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
		++grad[a]; ++grad[b];
	}
	for(int i=1; i<=n; ++i) if(1==grad[i]) g1.push_back(mp(i,1)),--cn,--grad[i];
	list<per>::iterator k=g1.begin();
	for(;cn;) {
		te=k->y;
		for(;te==k->y;++k)
			for(it i=gr[k->x].begin(); i!=gr[k->x].end(); ++i) {
				--grad[*i];
				if(1==grad[*i]) g1.push_back(mp(*i,te+1)),--cn;
			}
	}
	k=g1.end(); --k;
	te=k->y; s1=k->x;
	--k;
	if(te==k->y) s2=k->x;
	dfs(s1,0);
	int dmax=0;
	for(int i=1; i<=n; ++i) dmax=max(dmax,d[i]);
	if(s2) cout<<2*dmax-1;
	else cout<<2*dmax;
	return 0;
}
