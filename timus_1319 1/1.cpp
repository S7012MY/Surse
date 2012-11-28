#include <iostream>
#include <bitset>
using namespace std;

bitset<105> viz[105];

int n,m[105][105],nc;

int main()
{
	cin>>n;
	int x=1,y=n,lst=n;
	for(nc=1;nc<=n*n;++nc) {
		m[x][y]=nc;
		viz[x][y]=1;
		if(viz[1][1]) {
			if(x+1<=n) ++x,++y;
			else {
				++lst;
				y=1;
				x=lst;
			}
		}else {
			if(x+1<=n && y+1<=n) ++x,++y;
			else x=1,y=lst-1,--lst;
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) cout<<m[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}