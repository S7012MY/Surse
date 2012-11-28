#include <iostream>
#include <algorithm>
#include <set>
#define MAXB 20
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n,a[DN],nxt[MAXB][DN];//urmatorul bit de dupa numar
per cb[MAXB];
set<int> s;

int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i],s.insert(a[i]);
	for(int i=0; i<MAXB; ++i) {
		nxt[i][n+1]=n+1;
		for(int j=n; j; --j) {
			if(a[j]&(1<<i)) nxt[i][j]=j;
			else nxt[i][j]=nxt[i][j+1];
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<MAXB; ++j) cb[j]=make_pair(nxt[j][i],j);
		sort(cb,cb+MAXB);
		int nr=0;
		for(int j=0; j<MAXB && cb[j].x!=n; ++j) {
			nr|=(1<<cb[j].y);
			for(;j<MAXB-1 && cb[j+1].x==cb[j].x;++j,nr|=(1<<cb[j].y));
			s.insert(nr);
		}
	}
	cout<<s.size();
	return 0;
}