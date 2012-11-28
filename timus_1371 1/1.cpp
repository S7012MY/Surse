#include <iostream>
#include <vector>
#define DN 50005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,nrf[DN],sum;
vector<per> gr[DN];

void dfs(int s,int f,int cm) {
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(i->x!=f) {
		dfs(i->x,s,i->y);
		nrf[s]+=nrf[i->x];
	}
	++nrf[s];
	cout<<s<<' '<<nrf[s]<<'\n';
	sum+=(cm*nrf[s]);
}

int main()
{
	cin>>n;
	for(int i=1; i<n; ++i) {
		int a,b,c;
		cin>>a>>b>>c;
		gr[a].push_back(make_pair(b,c));
		gr[b].push_back(make_pair(a,c));
	}
	dfs(1,0,0);
	cout<<sum;
	return 0;
}