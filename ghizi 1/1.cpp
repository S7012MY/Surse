#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>
#define DN 103
using namespace std;

queue<int> c;
bitset<DN> viz;
vector<int> ct[DN][DN],sol;
int n,m,k,fm,fl[DN][DN],cap[DN][DN],pre[DN];

void flow() {
	memset(pre,-1,sizeof(pre));
	for(c.push(0);c.size();c.pop()) {
		int fr=c.front();
		for(int i=0; i<101; ++i) if(cap[fr][i]>fl[fr][i]&&-1==pre[i]) {
			c.push(i);
			pre[i]=fr;
		}
	}
	if(-1!=pre[100]) {
		++fm;
		for(int i=100;i; i=pre[i]) {
			++fl[pre[i]][i];
			--fl[i][pre[i]];
		}
	}
}


int main()
{
	ifstream f("ghizi.in");
	ofstream g("ghizi.out");
	f>>n>>k;
	for(int i=1; i<=n; ++i) {
		int t1,t2;
		f>>t1>>t2;
		++cap[t1][t2];
		ct[t1][t2].push_back(i);
	}
	for(int i=1; i<=k; ++i) flow();
	for(int i=0; i<101; ++i) for(int j=0; j<101; ++j)
		for(int k=1; k<=fl[i][j]; ++k) sol.push_back(ct[i][j][k-1]);
	sort(sol.begin(),sol.end());
	g<<sol.size()<<'\n';
	for(int i=0; i<sol.size(); ++i) g<<sol[i]<<' ';
	return 0;
}