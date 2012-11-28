#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define DN (1<<21)
using namespace std;

int n,m,dist[DN],dc,bit,goal;
int muc[205],cst[205],sz;
bitset<DN> inq;

queue<int> c;

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i) {
		muc[++sz]=(1<<i);
		cin>>cst[sz];
	}
	cin>>m;
	for(int i=0; i<m; ++i) {
		++sz;
		cin>>cst[sz];
		cin>>dc;
		int state=0;
		for(int j=0; j<dc; ++j) {
			cin>>bit;
			state+=(1<<(bit-1));
		}
		muc[sz]=state;
	}
	cin>>m;
	for(int i=1; i<=m; ++i) {
		cin>>bit;
		goal+=(1<<(bit-1));
	}
	dist[goal]=999999;
	for(c.push(0);c.size(); c.pop()) {
		int fr=c.front();
		//cout<<fr<<'\n';
		for(int i=1; i<=sz; ++i) {
			if(0==dist[fr|muc[i]] || dist[fr|muc[i]]>dist[fr]+cst[i]) {
				dist[fr|muc[i]]=dist[fr]+cst[i];
				//cout<<fr<<' '<<(fr|muc[i])<<' '<<dist[fr|muc[i]]<<'\n';
				if(((fr|muc[i])&goal)==goal) {
					dist[goal]=min(dist[goal],dist[fr|muc[i]]);
					//cout<<(fr|muc[i])<<' '<<goal<<'\n';
				}
				if(!inq[fr|muc[i]]) {
					c.push(fr|muc[i]);
					inq[fr|muc[i]]=1;
				}
			}
		}
		inq[fr]=0;
	}
	//cout<<(7&goal)<<'\n';
	cout<<dist[goal];
	return 0;
}